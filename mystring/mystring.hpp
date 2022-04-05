#ifndef __MYSTRING__
#define __MYSTRING__

#include <iostream>
#include <cstring>

namespace my { 

    class string
    { 
    public:
        // Default constructor
        string()
        {
            // std::cout << __PRETTY_FUNCTION__ << std::endl;
            m_str = new char[1];
            m_str[0] = '\0';
        }
        // Constructor with 1 argument
        explicit string(const char *s)
        {
            // std::cout << __PRETTY_FUNCTION__ << std::endl;
            m_str = new char[std::strlen(s)+1];
            std::strcpy(m_str,s);
        }
        
        // Copy constructor
        string(const string &other)
        : m_str(nullptr)
        {       
            //std::cout << __PRETTY_FUNCTION__ << std::endl;
            size_t s = other.size();
            if (s != -1)
            {
                m_str = new char[s+1];
                std::strcpy(m_str, other.m_str);           
            }
        }

        // Assignment operator
        string &
        operator=(const string &other)
        {
            // std::cout << __PRETTY_FUNCTION__ <<  std::endl;
            delete [] m_str;
            m_str = nullptr;

            size_t s = other.size();
            if (s != -1) {
                m_str = new char[s+1];
                std::strcpy(m_str, other.m_str);           
            }

            return *this;
        }

        // Move constructor
        string(string && other)
        : m_str(other.m_str)
        {
            // std::cout << __PRETTY_FUNCTION__ <<  std::endl;
            other.m_str = nullptr;
        }
        // Move assignment constructor
        
        string &
        operator=(string &&other)
        {                
            std::cout << __PRETTY_FUNCTION__ << std::endl;
            delete[] m_str;
            
            m_str = other.m_str;
            other.m_str = nullptr;

            return *this;
        }

        // Destructor        
        ~string()
        {
            //std::cout << __PRETTY_FUNCTION__ <<  std::endl;
            delete[] m_str; 
        }

        const char *
        c_str() const
        {
            return (m_str == nullptr ? "NULL" : m_str);
        }

        std::size_t
        size() const
        {
            return  (m_str == nullptr ? -1 : std::strlen(m_str));
        }
        
        // Operator bool
        operator bool() const {
            return (m_str != nullptr);
        }
        
        string &
        operator+=(const string &rhs)
        {                
        //    std::cout << __PRETTY_FUNCTION__ << std::endl;
            size_t mys = this->size();
            size_t s = rhs.size();

            int len = (mys < 0 ? 0 : mys) +
                      ( s  < 0 ? 0 : s);

            char * tmp = new char[len+1];
            tmp[0] = '\0';

            if (mys > 0)
                strcat(tmp, m_str);
            if (s > 0)
                strcat(tmp, rhs.m_str);
            
            m_str = tmp;
            return *this;
        }

        bool
        operator==(const string &rhs)
        {
//            std::cout << __PRETTY_FUNCTION__ << std::endl;
            if (m_str == NULL && rhs.m_str == NULL)
                return true;
             
            if (m_str && rhs.m_str)
                return strcmp(m_str, rhs.m_str) == 0;  
 
            return false;
        }
        bool
        operator!=(const string &rhs)
        {
//            std::cout << __PRETTY_FUNCTION__ << std::endl;
            return !(*this == rhs);
        }

    private:
        char *m_str;
    };

    string
    operator+(string tmp, const string &rhs) // why tmp passed by value? I must copy once in any case, hence...
    {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
        tmp+=rhs;
        return tmp;
    }

    bool
    operator<(const string &lhs, const string &rhs)
    {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
        if (lhs.c_str() == NULL && rhs.c_str() == NULL)
            return false;

        if (lhs.c_str() && rhs.c_str())
            return strcmp(lhs.c_str(), rhs.c_str()) < 0;  

        if (lhs.c_str() == NULL)
            return true;
        else
            return false;
    }
    
    bool
    operator>(const string &lhs, const string &rhs)
    {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return rhs < lhs;
    }

    bool
    operator<=(const string &lhs, const string &rhs)
    {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return !(lhs > rhs);
    }
    bool
    operator>=(const string &lhs, const string &rhs)
    {
//        std::cout << __PRETTY_FUNCTION__ << std::endl;
        return !(lhs < rhs);
    }


    std::ostream& operator<<(std::ostream &out, const string& rhs)
    {
        return out << (rhs.c_str() == nullptr ? "NULL" : rhs.c_str());
    }

} // namespace my


#endif
