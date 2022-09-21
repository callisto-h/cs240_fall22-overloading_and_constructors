#include "Sample.h"

#include <iostream>

/**
 * QUESTION:
 * 1. Why do we bother setting the val_ptr value
 * here?
 * ANSWER:
 * 1. We use "nullptr" to mean "unused". If we did
 * not do this, one could later assume that
 * the pointer actually points to something.
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
 * ANSWER:
 * 2. When creating a copy from another Sample, the
 * Sample's val_ptr either points to nothing (nullptr)
 * or it points to something.
 *
 * 3. In the first case, we simply copy the nullptr.
 * In the second, we have to use 'new' to allocate
 * space for our copy.
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
     * ANSWER:
     * 4. We are not simply copying the pointer value. We are
     * going to the "other" pointer, getting the value,
     * then making space for our copy to store it, and copying
     * the value.
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
 * ANSWER:
 * 5. We do the first check in the case that somebody
 * does : 'a = a'. If we did this, the line with
 * 'new' would execute, causing a memory leak.
 *
 * 6. Yes! Same "two case" structure as question 3
 *
 * 7. So that somebody could do 'a = b = c'.
 * Each pair has to resolve into something that matches
 * the function signature below. operator= works with 2
 * samples. 'b = c' returning a sample allows for
 * 'a = (b = c)' to work as well.
 */
Sample& Sample::operator=(Sample const &other){
    if (this == &other)
        return *this;

    if (other.val_ptr == nullptr){
        this->val_ptr = nullptr;
        return *this;
    }

    delete val_ptr;
    this->val_ptr = new int(*other.val_ptr);

    return *this;
}

/**
 * QUESTION:
 * 8. Why don't we need to use 'new' in our
 * second "case" in this function?
 *
 * ANSWER:
 * 8. If the val_ptr is not 'nullptr', we know
 * that space has been allocated for it using 'new'.
 * Since we know that, we can simply go to that
 * location that val_ptr points to, and adjust the value.
 * We COULD replace the last line in the function
 * with:
 *
 * delete val_ptr;
 * val_ptr = new int(v);
 *
 * but it is not necessary to do so.
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
 * ANSWER:
 * 9. Yeah, what if somebody set the value that val_ptr
 * points to to '0'? Then it being uninitialized or '0'
 * read the same. Very minor, but something to keep an
 * eye out for.
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
 * ANSWER:
 * 10. The delete line de-allocates the space on the heap
 * which was allocated by 'new'
 *
 * 11. I'm going to be super particuar here.
 * NOTHING happens to the pointer. The memory that the
 * pointer pointed to is de-allocated, but the pointer
 * still points.... somewhere!!!
 *
 * 12. I believe it is good practice to set unused pointers
 * to 'nullptr'. That way, other functions will know that
 * there is no active heap memory pointed to by the pointer:
 *
 * val_ptr = nullptr;
 */
void Sample::removeValue(){
    if(val_ptr == nullptr)
        return;

    delete val_ptr;
}

Sample::~Sample(){
    delete val_ptr;
}

std::ostream &operator<<(std::ostream &out, Sample const &s){
    if (s.val_ptr == nullptr)
    {
        out << "val_ptr (mem location): "
            << "nullptr";
        return out;
    }

    out << "val_ptr (mem location): " << std::hex << s.val_ptr;
    out << " | ";
    out << "*val_ptr (value)      : " << std::dec << *(s.val_ptr);

    return out;
}

std::istream &operator>>(std::istream &in, Sample &s)
{
    int temp;
    in >> std::dec >> temp;

    if (s.val_ptr == nullptr){
        s.val_ptr = new int(temp);
        return in;
    }

    *(s.val_ptr) = temp;
    return in;
}
