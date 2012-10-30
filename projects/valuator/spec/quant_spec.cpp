/**
   Copyright (C) 2008, 2009 Bojan Nikolic <bojan@bnikolic.co.uk>

   Simple bare-bones example of using QuantLib to price an FX option

   This program is distributed in the hope that it will be useful, but WITHOUT
   ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
   FOR A PARTICULAR PURPOSE.  See the license for more details.

   Comments welcome at bojan@bnikolic.co.uk
*/
#include <iostream>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE quant_spec
#include <boost/test/included/unit_test.hpp>
#include <ql/quantlib.hpp>

namespace {

const std::string empty;
const std::string test_module("quant");
const std::string test_suite("quant_spec");

using namespace QuantLib;

const QuantLib::Date current_date = Date(15, May, 1998);
const QuantLib::Date start_date = Date(17, May, 1998);
const QuantLib::Date maturity_date = Date(17, May, 1999);
const double epsilon_high = 0.00001;
const double epsilon_low = 0.000001;
const double epsilon_npv_high = 0.1;
const double epsilon_npv_low = -0.1;
const double epsilon_delta_high = 0.00001;
const double epsilon_delta_low = 0.000001;
const double epsilon_gamma_high = 0.00001;
const double epsilon_gamma_low = 0.000001;
const double epsilon_theta_high = 0.01;
const double epsilon_theta_low = 0.001;

/* Expected greeks values for tests */

const double expected_crr_npv = 6.65078;
const double expected_crr_delta = 0.498109;
const double expected_crr_gamma = 0.0217822;
const double expected_crr_theta = -2.72911;
const double expected_rho = 0;
const double expected_vega = 0;

const double expected_jr_npv = 6.66636;
const double expected_jr_delta = 0.498109;
const double expected_jr_gamma = 0.0217822;
const double expected_jr_theta = -2.72037;

const double expected_tian_npv = 6.67314;
const double expected_tian_delta = 0.498184;
const double expected_tian_gamma = 0.0217822;
const double expected_tian_theta = -2.71229;

const double expected_trig_npv = 6.65359;
const double expected_trig_delta = 0.498139;
const double expected_trig_gamma = 0.0217822;
const double expected_trig_theta = -2.72713;

const double expected_lr_npv = 6.60529;
const double expected_lr_delta = 0.498109;
const double expected_lr_gamma = 0.0219406;
const double expected_lr_theta = -2.76213;


struct OptionInputs {
  QuantLib::Real S;
  QuantLib::Real K;
  /// Foreign rate
  QuantLib::Spread f;
  /// Domestic rate
  QuantLib::Rate r;
  QuantLib::Volatility vol;
  QuantLib::Date maturity;
  QuantLib::DayCounter dayCounter;
};

OptionInputs populate_option_inputs() {
OptionInputs in;
    in.S = 100;
    in.K = 100;
    in.f = 0.05;
    in.r = 0.02;
    in.vol = 0.2;
    in.maturity = maturity_date;
    in.dayCounter = Actual365Fixed();

    return in;
}

enum tree {cox_ross_rubinstein, jarrow_rudd, tian, trigeorgis, leisen_reimer};

double Pricing(QuantLib::VanillaOption &o,
    boost::shared_ptr<QuantLib::GarmanKohlagenProcess> process,
    QuantLib::Size timeSteps, tree method) {

    using namespace QuantLib;

if (method == cox_ross_rubinstein) {	
    boost::shared_ptr<PricingEngine> pe(
        new BinomialVanillaEngine<CoxRossRubinstein>(process, timeSteps));
    o.setPricingEngine(pe);

} else if (method == jarrow_rudd) {
    boost::shared_ptr<PricingEngine> pe(
        new BinomialVanillaEngine<JarrowRudd>(process, timeSteps));
    o.setPricingEngine(pe);

} else if (method == tian) {
    boost::shared_ptr<PricingEngine> pe(
        new BinomialVanillaEngine<Tian>(process, timeSteps));
    o.setPricingEngine(pe);

} else if (method == trigeorgis) {
    boost::shared_ptr<PricingEngine> pe(
        new BinomialVanillaEngine<Trigeorgis>(process, timeSteps));
    o.setPricingEngine(pe);
} else if (method == leisen_reimer) {
    boost::shared_ptr<PricingEngine> pe(
        new BinomialVanillaEngine<LeisenReimer>(process, timeSteps));
    o.setPricingEngine(pe);
}
  return o.NPV();
}

boost::shared_ptr<QuantLib::GarmanKohlagenProcess> get_process(
    const OptionInputs &in, const QuantLib::Date &start_date) {

    using namespace QuantLib;

    // set up dates
    Calendar calendar = TARGET();

    boost::shared_ptr<SimpleQuote> riskFreeRate(new SimpleQuote(in.r));
    boost::shared_ptr<SimpleQuote> volatility(new SimpleQuote(in.vol));

    Handle<Quote> underlyingH(
        boost::shared_ptr<Quote>(new SimpleQuote(in.S)));

    Handle<YieldTermStructure> rTS(
        boost::shared_ptr<YieldTermStructure>(new FlatForward(start_date,
                Handle<Quote>(riskFreeRate), in.dayCounter)));

    Handle<YieldTermStructure> fTS(
        boost::shared_ptr<YieldTermStructure>(new FlatForward(start_date,
                in.f,
                in.dayCounter)));

    Handle<BlackVolTermStructure> flatVolTS(
        boost::shared_ptr<BlackVolTermStructure>(
            new BlackConstantVol(start_date,
                calendar,
                Handle<Quote>(volatility),
                in.dayCounter)));

    boost::shared_ptr<GarmanKohlagenProcess> process(
        new GarmanKohlagenProcess(underlyingH, fTS, rTS, flatVolTS));

    return process;
}


QuantLib::VanillaOption get_american_option(const OptionInputs &in,
    const QuantLib::Date &current_date,
    const QuantLib::Date &start_date) {

    using namespace QuantLib;

    // set up dates
    Calendar calendar = TARGET();
    Settings::instance().evaluationDate() = current_date;

    boost::shared_ptr<Exercise>
        americanExercise(new AmericanExercise(start_date, in.maturity));

    boost::shared_ptr<StrikedTypePayoff>
        payoff(new PlainVanillaPayoff(Option::Call, in.K));

    return VanillaOption(payoff, americanExercise);
}
}

BOOST_AUTO_TEST_SUITE(quant)

BOOST_AUTO_TEST_CASE(vanilla_option_should_be_priced_correctly) {
    using namespace QuantLib;

    OptionInputs in = populate_option_inputs();

    VanillaOption amerOpt =
        get_american_option(in, current_date, start_date);

    boost::shared_ptr<GarmanKohlagenProcess> process =
        get_process(in, start_date);

    double npv = Pricing(amerOpt, process, 100, cox_ross_rubinstein);

    BOOST_CHECK((npv - expected_crr_npv) < epsilon_high);
    BOOST_CHECK((npv - expected_crr_npv) > epsilon_low);
}


BOOST_AUTO_TEST_CASE(cox_ross_rubinstein_should_have_correct_values) {
    using namespace QuantLib;

    OptionInputs in = populate_option_inputs();

    VanillaOption amerOpt =
        get_american_option(in, current_date, start_date);

    boost::shared_ptr<GarmanKohlagenProcess> process =
        get_process(in, start_date);

    double npv = Pricing(amerOpt, process, 100, cox_ross_rubinstein);

    BOOST_CHECK((npv - expected_crr_npv) < epsilon_npv_high);
    BOOST_CHECK((npv - expected_crr_npv) > epsilon_npv_low);

    Real delta = amerOpt.delta();
    BOOST_CHECK((delta - expected_crr_delta) < epsilon_delta_high);
    BOOST_CHECK((delta - expected_crr_delta/10) > epsilon_delta_low);

    Real gamma = amerOpt.gamma();
    BOOST_CHECK((gamma - expected_crr_gamma) < epsilon_gamma_high);
    BOOST_CHECK((gamma - expected_crr_gamma / 10) > epsilon_gamma_low);

    Real theta = amerOpt.theta();
    BOOST_CHECK((theta - expected_crr_theta) < epsilon_theta_high);
    BOOST_CHECK((theta - expected_crr_theta) > -epsilon_theta_low);

    boost::shared_ptr<SimpleQuote> riskFreeRate(new SimpleQuote(in.r));
    boost::shared_ptr<SimpleQuote> volatility(new SimpleQuote(in.vol));

    Rate r0 = riskFreeRate->value();
    Spread dr = 0.0001;

    riskFreeRate->setValue(r0 + dr);
    Real P1 = amerOpt.NPV();

    riskFreeRate->setValue(r0 - dr);
    Real P2 = amerOpt.NPV();

    Real rho = (P1 - P2)/(2*dr);

    riskFreeRate->setValue(r0);

    Volatility v0 = volatility->value();
    Real dsigma = 0.0001;

    volatility->setValue(v0 + dsigma);
    Real F1 = amerOpt.NPV();

    volatility->setValue(v0 - dsigma);
    Real F2 = amerOpt.NPV();

    Real vega = (F1 - F2)/(2*dsigma);

    volatility->setValue(v0);

    BOOST_TEST_MESSAGE("Delta: " << delta);
    BOOST_TEST_MESSAGE("Gamma: " << gamma);
    BOOST_TEST_MESSAGE("Theta: " << theta);
    BOOST_TEST_MESSAGE("Rho:   " << rho);
    BOOST_TEST_MESSAGE("Vega:  " << vega);
}

BOOST_AUTO_TEST_CASE(jarrow_rudd_should_have_correct_values) {
    using namespace QuantLib;

    OptionInputs in = populate_option_inputs();

    VanillaOption amerOpt =
        get_american_option(in, current_date, start_date);

    boost::shared_ptr<GarmanKohlagenProcess> process =
        get_process(in, start_date);

    double npv = Pricing(amerOpt, process, 100, jarrow_rudd);

    BOOST_CHECK((npv - expected_jr_npv) < epsilon_npv_high);
    BOOST_CHECK((npv - expected_jr_npv) > epsilon_npv_low);

    Real delta = amerOpt.delta();
    BOOST_CHECK((delta - expected_jr_delta) < epsilon_delta_high);
    BOOST_CHECK((delta - expected_jr_delta/10) > epsilon_delta_low);

    Real gamma = amerOpt.gamma();
    BOOST_CHECK((gamma - expected_jr_gamma) < epsilon_gamma_high);
    BOOST_CHECK((gamma - expected_jr_gamma / 10) > epsilon_gamma_low);

    Real theta = amerOpt.theta();
    BOOST_CHECK((theta - expected_jr_theta) < epsilon_theta_high);
    BOOST_CHECK((theta - expected_jr_theta) > -epsilon_theta_low);

    boost::shared_ptr<SimpleQuote> riskFreeRate(new SimpleQuote(in.r));
    boost::shared_ptr<SimpleQuote> volatility(new SimpleQuote(in.vol));

    Rate r0 = riskFreeRate->value();
    Spread dr = 0.0001;

    riskFreeRate->setValue(r0 + dr);
    Real P1 = amerOpt.NPV();

    riskFreeRate->setValue(r0 - dr);
    Real P2 = amerOpt.NPV();

    Real rho = (P1 - P2)/(2*dr);

    riskFreeRate->setValue(r0);

    Volatility v0 = volatility->value();
    Real dsigma = 0.0001;

    volatility->setValue(v0 + dsigma);
    Real F1 = amerOpt.NPV();

    volatility->setValue(v0 - dsigma);
    Real F2 = amerOpt.NPV();

    Real vega = (F1 - F2)/(2*dsigma);

    volatility->setValue(v0);

    BOOST_TEST_MESSAGE("Delta: " << delta);
    BOOST_TEST_MESSAGE("Gamma: " << gamma);
    BOOST_TEST_MESSAGE("Theta: " << theta);
    BOOST_TEST_MESSAGE("Rho:   " << rho);
    BOOST_TEST_MESSAGE("Vega:  " << vega);
}

BOOST_AUTO_TEST_CASE(tian_should_have_correct_values) {
    using namespace QuantLib;

    OptionInputs in = populate_option_inputs();

    VanillaOption amerOpt =
        get_american_option(in, current_date, start_date);

    boost::shared_ptr<GarmanKohlagenProcess> process =
        get_process(in, start_date);

    double npv = Pricing(amerOpt, process, 100, tian);

    BOOST_CHECK((npv - expected_tian_npv) < epsilon_npv_high);
    BOOST_CHECK((npv - expected_tian_npv) > epsilon_npv_low);

    Real delta = amerOpt.delta();
    BOOST_CHECK((delta - expected_tian_delta) < epsilon_delta_high);
    BOOST_CHECK((delta - expected_tian_delta/10) > epsilon_delta_low);

    Real gamma = amerOpt.gamma();
    BOOST_CHECK((gamma - expected_tian_gamma) < epsilon_gamma_high);
    BOOST_CHECK((gamma - expected_tian_gamma / 10) > epsilon_gamma_low);

    Real theta = amerOpt.theta();
    BOOST_CHECK((theta - expected_tian_theta) < epsilon_theta_high);
    BOOST_CHECK((theta - expected_tian_theta) > -epsilon_theta_low);

    boost::shared_ptr<SimpleQuote> riskFreeRate(new SimpleQuote(in.r));
    boost::shared_ptr<SimpleQuote> volatility(new SimpleQuote(in.vol));

    Rate r0 = riskFreeRate->value();
    Spread dr = 0.0001;

    riskFreeRate->setValue(r0 + dr);
    Real P1 = amerOpt.NPV();

    riskFreeRate->setValue(r0 - dr);
    Real P2 = amerOpt.NPV();

    Real rho = (P1 - P2)/(2*dr);

    riskFreeRate->setValue(r0);

    Volatility v0 = volatility->value();
    Real dsigma = 0.0001;

    volatility->setValue(v0 + dsigma);
    Real F1 = amerOpt.NPV();

    volatility->setValue(v0 - dsigma);
    Real F2 = amerOpt.NPV();

    Real vega = (F1 - F2)/(2*dsigma);

    volatility->setValue(v0);

    BOOST_TEST_MESSAGE("Delta: " << delta);
    BOOST_TEST_MESSAGE("Gamma: " << gamma);
    BOOST_TEST_MESSAGE("Theta: " << theta);
    BOOST_TEST_MESSAGE("Rho:   " << rho);
    BOOST_TEST_MESSAGE("Vega:  " << vega);
}

BOOST_AUTO_TEST_CASE(trigeorgis_should_have_correct_values) {
    using namespace QuantLib;

    OptionInputs in = populate_option_inputs();

    VanillaOption amerOpt =
        get_american_option(in, current_date, start_date);

    boost::shared_ptr<GarmanKohlagenProcess> process =
        get_process(in, start_date);

    double npv = Pricing(amerOpt, process, 100, trigeorgis);

    BOOST_CHECK((npv - expected_trig_npv) < epsilon_npv_high);
    BOOST_CHECK((npv - expected_trig_npv) > epsilon_npv_low);

    Real delta = amerOpt.delta();
    BOOST_CHECK((delta - expected_trig_delta) < epsilon_delta_high);
    BOOST_CHECK((delta - expected_trig_delta/10) > epsilon_delta_low);

    Real gamma = amerOpt.gamma();
    BOOST_CHECK((gamma - expected_trig_gamma) < epsilon_gamma_high);
    BOOST_CHECK((gamma - expected_trig_gamma / 10) > epsilon_gamma_low);

    Real theta = amerOpt.theta();
    BOOST_CHECK((theta - expected_trig_theta) < epsilon_theta_high);
    BOOST_CHECK((theta - expected_trig_theta) > -epsilon_theta_low);

    boost::shared_ptr<SimpleQuote> riskFreeRate(new SimpleQuote(in.r));
    boost::shared_ptr<SimpleQuote> volatility(new SimpleQuote(in.vol));

    Rate r0 = riskFreeRate->value();
    Spread dr = 0.0001;

    riskFreeRate->setValue(r0 + dr);
    Real P1 = amerOpt.NPV();

    riskFreeRate->setValue(r0 - dr);
    Real P2 = amerOpt.NPV();

    Real rho = (P1 - P2)/(2*dr);

    riskFreeRate->setValue(r0);

    Volatility v0 = volatility->value();
    Real dsigma = 0.0001;

    volatility->setValue(v0 + dsigma);
    Real F1 = amerOpt.NPV();

    volatility->setValue(v0 - dsigma);
    Real F2 = amerOpt.NPV();

    Real vega = (F1 - F2)/(2*dsigma);

    volatility->setValue(v0);

    BOOST_TEST_MESSAGE("Delta: " << delta);
    BOOST_TEST_MESSAGE("Gamma: " << gamma);
    BOOST_TEST_MESSAGE("Theta: " << theta);
    BOOST_TEST_MESSAGE("Rho:   " << rho);
    BOOST_TEST_MESSAGE("Vega:  " << vega);
}

BOOST_AUTO_TEST_CASE(leisen_reimer_should_have_correct_values) {
    using namespace QuantLib;

    OptionInputs in = populate_option_inputs();

    VanillaOption amerOpt =
        get_american_option(in, current_date, start_date);

    boost::shared_ptr<GarmanKohlagenProcess> process =
        get_process(in, start_date);

    double npv = Pricing(amerOpt, process, 100, leisen_reimer);

    BOOST_CHECK((npv - expected_lr_npv) < epsilon_npv_high);
    BOOST_CHECK((npv - expected_lr_npv) > epsilon_npv_low);

    Real delta = amerOpt.delta();
    BOOST_CHECK((delta - expected_lr_delta) < epsilon_delta_high);
    BOOST_CHECK((delta - expected_lr_delta/10) > epsilon_delta_low);

    Real gamma = amerOpt.gamma();
    BOOST_CHECK((gamma - expected_lr_gamma) < epsilon_gamma_high);
    BOOST_CHECK((gamma - expected_lr_gamma / 10) > epsilon_gamma_low);

    Real theta = amerOpt.theta();
    BOOST_CHECK((theta - expected_lr_theta) < epsilon_theta_high);
    BOOST_CHECK((theta - expected_lr_theta) > -epsilon_theta_low);

    boost::shared_ptr<SimpleQuote> riskFreeRate(new SimpleQuote(in.r));
    boost::shared_ptr<SimpleQuote> volatility(new SimpleQuote(in.vol));

    Rate r0 = riskFreeRate->value();
    Spread dr = 0.0001;

    riskFreeRate->setValue(r0 + dr);
    Real P1 = amerOpt.NPV();

    riskFreeRate->setValue(r0 - dr);
    Real P2 = amerOpt.NPV();

    Real rho = (P1 - P2)/(2*dr);

    riskFreeRate->setValue(r0);

    Volatility v0 = volatility->value();
    Real dsigma = 0.0001;

    volatility->setValue(v0 + dsigma);
    Real F1 = amerOpt.NPV();

    volatility->setValue(v0 - dsigma);
    Real F2 = amerOpt.NPV();

    Real vega = (F1 - F2)/(2*dsigma);

    volatility->setValue(v0);

    BOOST_TEST_MESSAGE("Delta: " << delta);
    BOOST_TEST_MESSAGE("Gamma: " << gamma);
    BOOST_TEST_MESSAGE("Theta: " << theta);
    BOOST_TEST_MESSAGE("Rho:   " << rho);
    BOOST_TEST_MESSAGE("Vega:  " << vega);
}

BOOST_AUTO_TEST_SUITE_END()
