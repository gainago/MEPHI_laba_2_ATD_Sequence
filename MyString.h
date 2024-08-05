#ifndef MY_STRING_H
#define MY_STRING_H

class MyString
{
private:
    char* str;
    int length;
public:
    MyString()
    {
        str = nullptr;
        length = 0;
    }

    MyString(const char* str)
    {
        length = this->StrLen(str);
        this->str = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }

        this->str[length] = '\0';

    }

    ~MyString()
    {
        delete[] this->str;
    }

    int StrLen(const char* symbols) const
    {
        if(symbols == nullptr)
            throw "invalid link";
        int size = 0;
        while (symbols[size] != '\0') {
            size++;
        }
        return size;
    }

    void StrCopy(char *dest, const char* src)
    {
        int i = 0;
        while (src[i] != '\0')
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    MyString(const MyString& other)
    {
        length = other.StrLen(other.str);
        this->str = new char[length + 1];

        for (int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }

        this->str[length] = '\0';
    }

    MyString& operator=(const MyString& other)
    {
        if (this->str != nullptr)
        {
            delete[] str;
        }
        length = other.StrLen(other.str);
        this->str = new char[length + 1];
        for (int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';
        return *this;
    }

    MyString operator+(const MyString& other)
    {
        MyString newStr;
        int thisLength = this->StrLen(this->str);
        int otherLength = other.StrLen(other.str);

        newStr.length = thisLength + otherLength;

        newStr.str = new char[thisLength + otherLength + 1];

        for (int i = 0; i < thisLength; i++)
        {
            newStr.str[i] = this->str[i];
        }

        for (int j = 0; j < otherLength; j++)
        {
            newStr.str[thisLength + j] = other.str[j];
        }

        newStr.str[thisLength + otherLength] = '\0';

        return newStr;
    }

    friend std::ostream &operator<<(std::ostream &out, const MyString& myString)
    {
        return out << myString.str;
    }

    friend std::istream &operator>>(std::istream &in, MyString& myString)
    {
        char buffer[1000];
        in >> buffer;
        myString.length = myString.StrLen(buffer);
        delete[] myString.str;
        myString.str = new char[myString.length + 1];
        myString.StrCopy(myString.str, buffer);
        return in;
    }

    int GetLength() const
    {
        return length;
    }

    bool operator==(const MyString& other)
    {
        if (this->length != other.length)
        {
            return false;
        }

        for (int i = 0; i < this->length; i++)
        {
            if (this->str[i] != other.str[i])
            {
                return false;
            }
        }
        return true;
    }

    bool operator!=(const MyString& other)
    {
        return !(this->operator==(other));
    }

    char& operator [](int index)
    {
        return this->str[index];
    }

};

#endif