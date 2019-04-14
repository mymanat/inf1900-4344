/*
/ Created by Simon, Maxime, Simon and Samuel
/ Date : February 15, 2019
*/

#ifndef MAIN_COMPONENT_H
#define MAIN_COMPONENT_H

/**
 * Classe permettant de s'assurer que tous les autres composants possède une fonction d'initialisation
 */
class Component{
public:
    /**
    * Virtual function to initialize.
    **/
    virtual void init() = 0;
};

#endif //MAIN_COMPONENT_H
