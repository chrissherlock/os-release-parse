/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4; fill-column: 100 -*- */

#include <sstream>
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
    CPPUNIT_TEST(testShouldGetValueInQuotes);
    CPPUNIT_TEST(testShouldGetValueWithNoQuotes);
    CPPUNIT_TEST(testShouldGetLines);
    CPPUNIT_TEST(testShouldGetKeyValue);
    CPPUNIT_TEST(testShouldGetKeyValues);
    CPPUNIT_TEST_SUITE_END();

protected:
    void testShouldGetName();
    void testShouldGetValueInQuotes();
    void testShouldGetValueWithNoQuotes();
    void testShouldGetKeyValue();
    void testShouldGetKeyValues();
    void testShouldGetLines();
};

void TestParser::testShouldGetName()
{
    std::string line("CPE_NAME=\"cpe:/o:fedoraproject:fedora:17\"");
    CPPUNIT_ASSERT_EQUAL(std::string("CPE_NAME"), GetName(line));
}

void TestParser::testShouldGetValueInQuotes()
{
    std::string line("CPE_NAME=\"cpe:/o:fedoraproject:fedora:17\"");
    CPPUNIT_ASSERT_EQUAL(std::string("cpe:/o:fedoraproject:fedora:17"), GetValue(line));
}

void TestParser::testShouldGetValueWithNoQuotes()
{
    std::string line("CPE_NAME=cpe:/o:fedoraproject:fedora:17");
    CPPUNIT_ASSERT_EQUAL(std::string("cpe:/o:fedoraproject:fedora:17"), GetValue(line));
}

void TestParser::testShouldGetLines()
{
    std::string inputlines("NAME=Fedora\nVERSION=\"17 (Beefy Miracle)\"");
    std::istringstream istm(inputlines);

    std::vector<std::string> lines = GetLines(istm);

    CPPUNIT_ASSERT_EQUAL(std::string("NAME=Fedora"), lines[0]);
    CPPUNIT_ASSERT_EQUAL(std::string("VERSION=\"17 (Beefy Miracle)\""), lines[1]);
}

void TestParser::testShouldGetKeyValue()
{
    std::string line("CPE_NAME=\"cpe:/o:fedoraproject:fedora:17\"");
    auto [key, value] = GetKeyValue(line);

    CPPUNIT_ASSERT_EQUAL(std::string("CPE_NAME"), key);
    CPPUNIT_ASSERT_EQUAL(std::string("cpe:/o:fedoraproject:fedora:17"), value);
}

void TestParser::testShouldGetKeyValues()
{
    std::string inputlines("NAME=Fedora\nVERSION=\"17 (Beefy Miracle)\"");
    std::istringstream istm(inputlines);

    std::vector<std::string> lines = GetLines(istm);
    auto records = GetKeyValues(lines);

    CPPUNIT_ASSERT_EQUAL(std::string("NAME"), records[0].first);
    CPPUNIT_ASSERT_EQUAL(std::string("Fedora"), records[0].second);
    CPPUNIT_ASSERT_EQUAL(std::string("VERSION"), records[1].first);
    CPPUNIT_ASSERT_EQUAL(std::string("17 (Beefy Miracle)"), records[1].second);
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
