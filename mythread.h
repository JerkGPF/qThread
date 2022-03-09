#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>
#include <QThread>
#include <QVector>
class Generate : public QThread
{
    Q_OBJECT
public:
    explicit Generate(QObject *parent = nullptr);

    void recvNum(int num);
protected:
    void run() override;
signals:
    void sendData(QVector<int> data);

private:
    int m_num;

};

class BubbleSort : public QThread
{
    Q_OBJECT
public:
    explicit BubbleSort(QObject *parent = nullptr);

    void recvArray(QVector<int> data);
protected:
    void run() override;
signals:
    void finish(QVector<int> data);

private:
    QVector<int> m_data;

};

class QuickSort : public QThread
{
    Q_OBJECT
public:
    explicit QuickSort(QObject *parent = nullptr);

      void recvArray(QVector<int> data);
protected:
    void run() override;
private:
    void quickSort(QVector<int> &data,int l,int r);
signals:
    void finish(QVector<int> data);

private:
    QVector<int> m_data;

};

#endif // MYTHREAD_H
