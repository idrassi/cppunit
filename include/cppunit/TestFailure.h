#ifndef CPPUNIT_TESTFAILURE_H    // -*- C++ -*-
#define CPPUNIT_TESTFAILURE_H

#include <cppunit/Portability.h>
#include <string>

CPPUNIT_NS_BEGIN


class Exception;
class SkipException;
class SourceLine;
class Test;

class CPPUNIT_API TestOutcome 
{
public:

  virtual ~TestOutcome () {}

  virtual Exception *thrownException() const = 0;

};

/*! \brief Record of a failed Test execution.
 * \ingroup BrowsingCollectedTestResult
 *
 * A TestFailure collects a failed test together with
 * the caught exception.
 *
 * TestFailure assumes lifetime control for any exception
 * passed to it.
 */
class CPPUNIT_API TestFailure : public TestOutcome
{
public:
  TestFailure( Test *failedTest,
               Exception *thrownException,
               bool isError );

  virtual ~TestFailure ();

  virtual Test *failedTest() const;

  virtual Exception *thrownException() const;

  virtual SourceLine sourceLine() const;

  virtual bool isError() const;

  virtual std::string failedTestName() const;

  virtual TestFailure *clone() const;

protected:
  Test *m_failedTest;
  Exception *m_thrownException;
  bool m_isError;

private: 
  TestFailure( const TestFailure &other ); 
  TestFailure &operator =( const TestFailure& other ); 
};

class CPPUNIT_API TestSkipped : public TestOutcome
{
public:
  TestSkipped( Test *skippedTest,
               SkipException *thrownException);

  virtual ~TestSkipped ();

  virtual Test *skippedTest() const;

  virtual Exception *thrownException() const;

  virtual SourceLine sourceLine() const;

  virtual std::string skippedTestName() const;

  virtual TestSkipped *clone() const;

protected:
  Test *m_skippedTest;
  SkipException *m_thrownException;

private: 
  TestSkipped( const TestSkipped &other ); 
  TestSkipped &operator =( const TestSkipped& other ); 
};

CPPUNIT_NS_END

#endif // CPPUNIT_TESTFAILURE_H
