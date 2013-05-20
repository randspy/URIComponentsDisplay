//Downloaded from http://qtcreator.blogspot.com/2009/10/running-multiple-unit-tests.html

#ifndef AUTOTEST_H
#define AUTOTEST_H

#include <QTest>
#include <QList>
#include <QString>
#include <QSharedPointer>
#include <iostream>

#define QVERIFY_THROW(expression, ExpectedExceptionType) \
do \
{ \
    bool caught_ = false; \
    try { expression; } \
    catch (ExpectedExceptionType const&) { caught_ = true; } \
    catch (...) {} \
    if (!QTest::qVerify(caught_, #expression ", " #ExpectedExceptionType, "", __FILE__, __LINE__))\
        return; \
} while(0);

namespace AutoTest
{
 typedef QList<QObject*> TestList;

 inline TestList& testList()
 {
  static TestList list;
  return list;
 }

 inline bool findObject(QObject* object)
 {
  TestList& list = testList();
  if (list.contains(object))
  {
   return true;
  }
  foreach (QObject* test, list)
  {
   if (test->objectName() == object->objectName())
   {
    return true;
   }
  }
  return false;
 }

 inline void addTest(QObject* object)
 {
  TestList& list = testList();
  if (!findObject(object))
  {
   list.append(object);
  }
 }

 inline int run(int argc, char *argv[])
 {
  int ret = 0;

  std::cout << "argc " << argc << std::endl;

  foreach (QObject* test, testList())
  {
   ret += QTest::qExec(test, argc, argv);
  }

  return ret;
 }
}

template <class T>
class Test
{
public:
 QSharedPointer<T> child;

 Test(const QString& name) : child(new T)
 {
  child->setObjectName(name);
  AutoTest::addTest(child.data());
 }
};

#define DECLARE_TEST(className) static Test<className> t(#className);

#define TEST_MAIN \
 int main(int argc, char *argv[]) \
 { \
  return AutoTest::run(argc, argv); \
 }

#endif // AUTOTEST_H
