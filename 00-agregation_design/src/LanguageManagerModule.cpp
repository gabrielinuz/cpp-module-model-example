/**
 * @file LanguageManagerModule.cpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief Source of Language Manager Module Example
 * @version 0.1
 * @date 2022-10-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */
#include <LanguageManagerModule.hpp>

/**
 * @brief Construct a new Language Manager Module:: Language Manager Module object
 * 
 */
LanguageManagerModule::LanguageManagerModule()
{
    _language = "default";
    _languageFilePath = "./lang/"+_language+".lang";
}

/**
 * @brief Destroy the Language Manager Module:: Language Manager Module object
 * 
 */
LanguageManagerModule::~LanguageManagerModule()
{
}

/**
 * @brief 
 * 
 * @param filePath 
 */
void LanguageManagerModule::setLanguageFilePath(string filePath) 
{
    _languageFilePath = filePath;
}

/**
 * @brief 
 * 
 * @param language 
 */
void LanguageManagerModule::setLanguage(string language) 
{
    _language = language;
    _languageFilePath = "./lang/"+_language+".lang";
}

/**
 * @brief 
 * @param key 
 * @return string 
 */
string LanguageManagerModule::translate(string key) 
{
    string result;
    _configReader->open(_languageFilePath);
    result =_configReader->getValueOf(key);
    if(result == "")
    {
        result = "NULL TRANSLATION OF KEY: " + key + "!";
    } 
    return result;
}

/**
 * @brief implements Configurable interface.
 * 
 * @param configReader 
 */
void LanguageManagerModule::setConfigReader(shared_ptr<ConfigReader> configReader) 
{
    _configReader = configReader;
}

/**
 * @brief Get the Instance object
 * 
 * @return shared_ptr<LanguageManager> 
 */
shared_ptr<ConfigurableLanguageManager> getInstanceOf(string typeId) 
{
    /**
     * @brief DEBUG
     * 
     */
    // cout << "Type ID Parameter Requested: " << typeId << endl;
    // cout << "Type ID Local Provided: " << typeid(shared_ptr<LanguageManager>).name() << endl;

    /**
     * @brief This...
     * 
     */
    return typeid(shared_ptr<ConfigurableLanguageManager>).name() == typeId ?
                 make_shared<LanguageManagerModule>() : nullptr;
                 
    /**
     * @brief ...instead this:
     * 
     */
    // shared_ptr<LanguageManager> instance = nullptr;
    // if (typeid(shared_ptr<LanguageManager>).name() == typeId )
    //     instance = make_shared<LanguageManagerModule>();
    // return instance;
    /**
     * @brief ...or this:
     * 
     */    
    // if (typeid(shared_ptr<LanguageManager>).name() == typeId )
    // { 
    //     return make_shared<LanguageManagerModule>(); 
    // }
    // else
    // {
    //     return nullptr;
    // }                 
}