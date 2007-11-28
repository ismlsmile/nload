
#ifndef SETTINGFILTER_H
#define SETTINGFILTER_H

#include <map>
#include <string>

class SettingFilter
{
    public:
        virtual ~SettingFilter() {}

        virtual std::string getId() const = 0;

        virtual bool filterWrite(std::string& valueNew) = 0;
        virtual void filterRead(std::string& value) = 0;
};

class SettingFilterMap : public SettingFilter
{
    public:
        SettingFilterMap(const std::map<std::string, std::string>& filterMap);
        ~SettingFilterMap();

        std::string getId() const;

        void setMap(const std::map<std::string, std::string>& filterMap);
        const std::map<std::string, std::string>& getMap() const;

        bool filterWrite(std::string& valueNew);
        void filterRead(std::string& value);
        
    private:
        std::map<std::string, std::string> m_filterMap;
};

class SettingFilterMin : public SettingFilter
{
    public:
        SettingFilterMin(int min);
        ~SettingFilterMin();

        std::string getId() const;

        void setMin(int min);
        int getMin() const;

        bool filterWrite(std::string& valueNew);
        void filterRead(std::string& value);
        
    private:
        int m_min;
};

class SettingFilterMax : public SettingFilter
{
    public:
        SettingFilterMax(int max);
        ~SettingFilterMax();

        std::string getId() const;

        void setMax(int max);
        int getMax() const;

        bool filterWrite(std::string& valueNew);
        void filterRead(std::string& value);
        
    private:
        int m_max;
};

#endif

