#ifndef CLASSIDENTIFIER_H
#define CLASSIDENTIFIER_H
#include <deque>
#include <mutex>

/**
 * TODO:
 * neede to be refactor. In my case unsigned ling long int will not be filled, but in some other cases .....
 */
class ClassIdentifier
{
    static unsigned long long int counter;

    void increaseCounter();
    std::deque<unsigned long long int> mIdList;
    std::mutex mMutex;
public:
    ClassIdentifier();
    ~ClassIdentifier();


    unsigned long long int  add(const void *classPt_in);
    void *                  get(unsigned long long int identifier);
    void                    remove(unsigned long long int identifier);
};

#endif // CLASSIDENTIFIER_H
