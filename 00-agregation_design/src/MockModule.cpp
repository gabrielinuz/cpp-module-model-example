/**
 * @file MockModule.cpp
 * @author Gabriel Ferreira (gferreiragabriel@abc.gob.ar)
 * @brief Source of MockModule
 * @version 0.1
 * @date 2024-04-26
 * 
 * @copyright Copyright (c) 2022 Released under the MIT license
 * @link https://opensource.org/licenses/MIT @endlink
 * 
 */
#include <MockModule.hpp>

/**
 * @brief Construct a new Language Manager Module:: Language Manager Module object
 * 
 */
MockModule::MockModule()
{
    _language = "default";
    _languageFilePath = "./lang/"+_language+".lang";
}

/**
 * @brief Destroy the Language Manager Module:: Language Manager Module object
 * 
 */
MockModule::~MockModule()
{
}

/**
 * @brief 
 * 
 * @param filePath 
 */
void MockModule::setLanguageFilePath(string filePath) 
{
    _languageFilePath = filePath;
}

/**
 * @brief 
 * 
 * @param language 
 */
void MockModule::setLanguage(string language) 
{
    _language = language;
    _languageFilePath = "./lang/"+_language+".lang";
}

/**
 * @brief 
 * @param key 
 * @return string 
 */
string MockModule::translate(string key) 
{
    return "NULL TRANSLATION OF KEY: " + key + "!";
}

/**
 * @brief Get the Instance object
 * 
 * @return shared_ptr<MockInterface> 
 */
shared_ptr<MockInterface> getInstanceOf(string typeId) 
{
    /**
     * @brief DEBUG
     * 
     */
    cout << "Type ID Parameter Requested: " << typeId << endl;
    cout << "Type ID Local Provided: " << typeid(shared_ptr<MockInterface>).name() << endl;

    return typeid(shared_ptr<MockInterface>).name() == typeId ?
                 std::make_shared<MockModule>() : nullptr;

    /**
     * @brief Another if mode:
     * 
     */
    // shared_ptr<MockInterface> instance = nullptr;
    
    // if (typeid(shared_ptr<MockInterface>).name() == typeId )
    //     instance = make_shared<MockModule>();
    
    // return instance;
}
