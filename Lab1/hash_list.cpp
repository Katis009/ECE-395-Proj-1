#include "hash_list.h"

hash_list::hash_list() {
    head = NULL;
    size = 0;
}

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/


void hash_list::insert(int key, float value) {

    node *curr = head;
    while (curr != NULL){
        if (key == curr->key){
            curr->value = value;
            return;
        }
        curr = curr->next;
    }
    node *newNode = new node();
    newNode->key = key;
    newNode->value = value;
    newNode->next = head;
    head = newNode;
    return;

}

std::optional<float> hash_list::get_value(int key) const { 
    node *curr = head;
    while (curr != NULL){
        if (curr->key == key){
            return curr->value;
        }
        curr = curr->next;
    }
    
    return std::nullopt; 
}

bool hash_list::remove(int key) { 
    
    if (head->key == key){
        node *delMe = head;
        head = head->next;
        delete delMe;
        return true;
    }

    node *curr = head;
    while (curr->next != NULL){
        if (curr->next->key == key){
            node *temp = curr->next;
            curr->next = temp->next;
            delete temp;
            return true;
        }
        curr = curr->next;
    }
    
    return false; 
}

size_t hash_list::get_size() const { 
    int var = size;       //do i need const here?
    return var;
    return 0; 
}

hash_list::~hash_list() {

    while (head != NULL){
        node *temp = head;
        head = head->next;
        delete temp;
    }

}

/**-----------------------------------------------------------------------------------
 * END Part 1
 *------------------------------------------------------------------------------------*/


/**-----------------------------------------------------------------------------------
 * START Part 2
 *------------------------------------------------------------------------------------*/

hash_list::hash_list(const hash_list &other) {}

hash_list &hash_list::operator=(const hash_list &other) { return *this; }

void hash_list::reset_iter() {}


void hash_list::increment_iter() {}


std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() { return std::nullopt; }


bool hash_list::iter_at_end() { return false; }
/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
