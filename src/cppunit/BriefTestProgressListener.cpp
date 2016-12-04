#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/Test.h>
#include <cppunit/TestFailure.h>
#include <cppunit/portability/Stream.h>


CPPUNIT_NS_BEGIN


BriefTestProgressListener::BriefTestProgressListener()
    : m_lastTestFailed( false ), m_lastTestSkipped( false )
{
}


BriefTestProgressListener::~BriefTestProgressListener()
{
}


void 
BriefTestProgressListener::startTest( Test *test )
{
  stdCOut() << test->getName();
  stdCOut().flush();

  m_lastTestFailed = false;
}


void 
BriefTestProgressListener::addFailure( const TestFailure &failure )
{
  stdCOut() << " : " << (failure.isError() ? "error" : "assertion");
  m_lastTestFailed  = true;
}

void 
BriefTestProgressListener::addSkipped( const TestSkipped &skipped )
{
  stdCOut() << " : " << "skipped";
  m_lastTestSkipped  = true;
}

void 
BriefTestProgressListener::endTest( Test * )
{
  if ( !m_lastTestFailed )
    stdCOut()  <<  " : OK";
  stdCOut() << "\n";
}


CPPUNIT_NS_END

