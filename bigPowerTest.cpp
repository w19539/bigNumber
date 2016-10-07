//
// Created by wentingyang on 2016/9/5.
//
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
#include <ctime>
#include <iostream>
#include "bigPower.h"

BOOST_AUTO_TEST_CASE( test_correctness )
{
    cout << "test case 1: testing correctness..." << endl;

    bigNum res;
    res = bigNumPow( 0, 0);

    cout << "base = 0, power = 0" << endl;
    BOOST_CHECK( !res.toString().compare("1") );

    cout << "base = 12, power = 21" << endl;
    res = bigNumPow( 12, 21);
    BOOST_CHECK( !res.toString().compare("46005119909369701466112") );

    cout << "base = 123, power = 321" << endl;
    res = bigNumPow( 123, 321);
    BOOST_CHECK( !res.toString().compare("7236703380637167314910989414116377862881179265757165890601055839039587"
                                                 "03637984017440952806861555077364049216570702849617218289605929"
                                                 "77909542637098897697223102622628566787654091327825453991595140"
                                                 "205701412961364188732408936197890553699715836951569999800431957"
                                                 "769217006743321026257517932764164662319487914962533302741368207"
                                                 "211189494615326552790667720411285474162636765168907211924134973"
                                                 "374304496019635376665858559941735703924836467756917247995469583"
                                                 "487467791524582153744522107597865277798136080074161485280424274"
                                                 "076931083994487111719562249702540362855712911132265966235754355"
                                                 "353516703339043001506118520760359577737869472018617942120590873"
                                                 "170710805078696371738906375721785723") );

    cout << "base = 91, power = 19" << endl;
    res = bigNumPow( 91, 19);
    BOOST_CHECK( !res.toString().compare("16664276159359979836134597478321347811") );

    cout << "base = -1, power = 0" << endl;
    res = bigNumPow( -1, 0);
    BOOST_CHECK( !res.toString().compare("") );

    cout << "base = -999999, power = 0" << endl;
    res = bigNumPow( 999999, 0);
    BOOST_CHECK( !res.toString().compare("") );
}

BOOST_AUTO_TEST_CASE( test_performance )
{
    cout << "test case 2: testing performance of 99999^99999..." << endl;
    bigNum res;
    const clock_t begin_time = clock();
    res = bigNumPow( 99999, 99999);
    std::cout << "execution time (base = 99999): " << float( clock () - begin_time )/CLOCKS_PER_SEC << "seconds" << endl;
}