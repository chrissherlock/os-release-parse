/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; fill-column: 100 -*- */

#include <string>

#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TestAssert.h>
#include <cppunit/TestFixture.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/extensions/HelperMacros.h>
#include <cppunit/plugin/TestPlugIn.h>

#include "parser.hpp"

class TestParser : public CppUnit::TestFixture
{
    CPPUNIT_TEST_SUITE(TestParser);
    CPPUNIT_TEST(testShouldGetName);
    CPPUNIT_TEST_SUITE_END();

protected:
    void testShouldGetName();
};

void TestParser::testShouldGetName()
{
    std::string line("CPE_NAME=\"cpe:/o:fedoraproject:fedora:17\"");
    CPPUNIT_ASSERT(GetName(line) == "CPE_NAME");
}

CPPUNIT_TEST_SUITE_REGISTRATION(TestParser);

// credit: http://www.yolinux.com/TUTORIALS/CppUnit.html

int main(int argc, char* argv[])
{
    // informs test-listener about testresults
    CPPUNIT_NS::TestResult testresult;

    // register listener for collecting the test-results
    CPPUNIT_NS::TestResultCollector collectedresults;
    testresult.addListener (&collectedresults);

    // register listener for per-test progress output
    CPPUNIT_NS::BriefTestProgressListener progress;
    testresult.addListener (&progress);

    // insert test-suite at test-runner by registry
    CPPUNIT_NS::TestRunner testrunner;
    testrunner.addTest (CPPUNIT_NS::TestFactoryRegistry::getRegistry().makeTest());
    testrunner.run(testresult);

    // output results in compiler-format
    CPPUNIT_NS::CompilerOutputter compileroutputter(&collectedresults, std::cerr);
    compileroutputter.write ();

    // return 0 if tests were successful
    return collectedresults.wasSuccessful() ? 0 : 1;
}

/* vim:set shiftwidth=4 softtabstop=4 expandtab cinoptions=b1,g0,N-s cinkeys+=0=break: */
