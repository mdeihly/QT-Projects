#include <QTest>
// #include <QCoreApplication>

#include "../ApplicationLib/divideexample.h"

class DivideExampleTest : public QObject
{
    Q_OBJECT

public:
    DivideExampleTest();
    ~DivideExampleTest();

private slots:
    // called before the first test
    void initTestCase();
    // called after the last test
    void cleanupTestCase();

    void divideReturnCorrectValue();
    void divideReturnDifferentValue();
    void divideThrowsInvalidArgument();

private:
    Example::DivideExample *divExample;

};

DivideExampleTest::DivideExampleTest()
{
    divExample = new Example::DivideExample;
}

DivideExampleTest::~DivideExampleTest()
{
    delete divExample;
}

void DivideExampleTest::initTestCase()
{
    qInfo("First Test...");
}

void DivideExampleTest::cleanupTestCase()
{
    qInfo("Testing done...");
}

void DivideExampleTest::divideReturnCorrectValue()
{
    QCOMPARE(divExample->divide(5,2), 2.5);
}

void DivideExampleTest::divideReturnDifferentValue()
{
    QCOMPARE(divExample->divide(10,2), 5);
}

void DivideExampleTest::divideThrowsInvalidArgument()
{
    QVERIFY_EXCEPTION_THROWN(divExample->divide(6,0), std::invalid_argument);
}

QTEST_MAIN(DivideExampleTest)

#include "tst_divideexampletest.moc"
