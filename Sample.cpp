#include "Sample.h"

#include <iostream>

/**
 * QUESTION:
 * 1. Why do we bother setting the val_ptr value
 * here?
 */
Sample::Sample(){
    val_ptr = nullptr;
}

Sample::Sample(int v){
    val_ptr = new int(v);
}

/**
 * QUESION:
 * 2. Why is the copy constructor written like this?
 *
 * 3. What are the two "cases" that then author
 * is expecting and how does the code address them?
 */
Sample::Sample(Sample const &other){

    if(other.val_ptr == nullptr){
        this->val_ptr = nullptr;
        return;
    }

    /**
     * QUESTION:
     * 4. Explain what this line is doing. Maybe draw
     * a picture.
     * Hint: Why can't we do "this-val_ptr = other.val_ptr"?
     */
    this->val_ptr = new int(*other.val_ptr);
}

/**
 * QUESTION:
 * 5. Why do we do the first check in this function?
 *
 * 6. Do you see any similarities to the Copy Constructor
 *
 * 7. Why do we return *this?
 */
Sample& Sample::operator=(Sample const &other){
    if (this == &other)
        return *this;

    if (other.val_ptr == nullptr){
        this->val_ptr = nullptr;
        return *this;
    }

    this->val_ptr = new int(*other.val_ptr);

    return *this;
}

/**
 * QUESTION:
 * 8. Why don't we need to use 'new' in our
 * second "case" in this function?
 *
 */
void Sample::setValue(int v){
    if(val_ptr == nullptr){
        val_ptr = new int(v);
        return;
    }

    *val_ptr = v;
}
/**
 * QUESTION:
 * 9. See any possible issues with this function?
 */
int Sample::getValue()
{
    if (val_ptr == nullptr)
        return 0;

    return *val_ptr;
}

/**
 * QUESTION:
 * 10. What does the 'delete' line do?
 *
 * 11. What happens to the pointer?
 *
 * 12. What are we missing from this function?
 *
 */
void Sample::removeValue(){
    if(val_ptr == nullptr)
        return;

    delete val_ptr;
}

Sample::~Sample(){
    delete val_ptr;
}
