class String
{
    char* string;
public:
    String() { string = NULL; }
    String(const char *str)
    {
        string = new char[strlen(str) + 1];
        strcpy(string, str);
        string[strlen(str)] = '\0';
    }
    ~String() { if (string) delete[] string; }
    void print() { cout << string << endl; }
    const char* getString()
    {
        if (string)
            return string;
        else
            return NULL;
    }
    bool operator==(String &s2)
    {
        bool Bool = 0;
        if (strlen(string) == strlen(s2.getString()))
        {
            Bool = 1;
            for (int i = 0; i < strlen(string); i++)
                if (string[i] != s2.getString()[i])
                    Bool = 0;
        }
        return Bool;
    }
    bool operator<(String &s2)
    {
        bool Bool = 0;
        for (int i = 0; i < min1(strlen(this->string), strlen(s2.getString())); i++)
        {
            if (this->string[i] == s2.getString()[i])
            {
                Bool = 1;
                continue;
            }
            if (this->string[i] < s2.getString()[i])
                    {
                Bool = 0;
                return TRUE;
            }
            if (this->string[i] > s2.getString()[i])
            {
                Bool = 0;
                return FALSE;
            }
        }
        if (Bool)
            if (strlen(string) < strlen(s2.getString()))
                return TRUE;
            else
                return FALSE;
        return FALSE;
    }
    bool operator>(String &s2)
    {
        bool Bool = 0;
        for (int i = 0; i < min1(strlen(this->string), strlen(s2.getString())); i++)
        {
            if (this->string[i] == s2.getString()[i])
            {
                Bool = 1;
                continue;
            }
            if (this->string[i] > s2.getString()[i])
            {
                Bool = 0;
                return TRUE;
            }
            if (this->string[i] < s2.getString()[i])
            {
                Bool = 0;
                return FALSE;
            }
        }
        if (Bool)
            if (strlen(string) > strlen(s2.getString()))
                return TRUE;
            else
                return FALSE;
        return FALSE;
    }
    String& operator=(String &s2)
    {
        if (!s2.getString())
        {
            delete[] string;
            return *this;
        }
        if (string) delete[] string;
        string = new char[strlen(s2.getString())+1];
        strcpy(string, s2.getString());
        string[strlen(s2.getString())] = '\0';
        return *this;
    }
    String& operator=(const char *str2)
    {
        if (!str2)
        {
                    delete[] string;
            return *this;
        }
        if (string) delete[] string;
        string = new char[strlen(str2) + 1];
        strcpy(string, str2);
        string[strlen(str2)] = '\0';
        return *this;
    }
    String operator+(String &s2)
    {
        char buf[255];
        strcpy(buf, string);
        return String(strcat(buf, s2.getString()));
    }
    friend ostream& operator<<(ostream& c0ut, String &s1);
    friend istream& operator >> (istream& c1n, String &s1);
};
