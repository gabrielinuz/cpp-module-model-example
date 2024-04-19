/**
 * @file LanguageManagerModuleTest.cpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief Source of Language Manager Module Example
 * @version 0.1
 * @date 2022-10-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */
#include <LanguageManagerModuleTest.hpp>

/**
 * @brief Construct a new Language Manager Module:: Language Manager Module object
 * 
 */
LanguageManagerModuleTest::LanguageManagerModuleTest()
{
    _language = "default";
    _languageFilePath = "./lang/"+_language+".lang";
}

/**
 * @brief Destroy the Language Manager Module:: Language Manager Module object
 * 
 */
LanguageManagerModuleTest::~LanguageManagerModuleTest()
{
}

/**
 * @brief 
 * 
 * @param filePath 
 */
void LanguageManagerModuleTest::setLanguageFilePath(string filePath) 
{
    _languageFilePath = filePath;
}

/**
 * @brief 
 * 
 * @param language 
 */
void LanguageManagerModuleTest::setLanguage(string language) 
{
    _language = language;
    _languageFilePath = "./lang/"+_language+".lang";
}

/**
 * @brief 
 * @param key 
 * @return string 
 */
string LanguageManagerModuleTest::translate(string key) 
{
    string result;
    _langReader = make_shared<LangReader>();//NOT NEW
    _langReader->open(_languageFilePath);
    result =_langReader->getValueOf(key);
    if(result == "")
    {
        result = "NULL TRANSLATION OF KEY: " + key + "!";
    } 
    return result;
}

/**
 * @brief Get the Instance object
 * 
 * @return shared_ptr<LanguageManagerTest> 
 */
shared_ptr<LanguageManagerTest> getInstanceOf(string typeId) 
{
    /**
     * @brief DEBUG
     * 
     */
    cout << "Type ID Parameter Requested: " << typeId << endl;
    cout << "Type ID Local Provided: " << typeid(shared_ptr<LanguageManagerTest>).name() << endl;

    return ( typeid(shared_ptr<LanguageManagerTest>).name() == typeId )?
                 std::make_shared<LanguageManagerModuleTest>() : nullptr;
}
