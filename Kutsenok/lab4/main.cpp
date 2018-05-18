#include <assert.h>
#include <algorithm>
#include <stdexcept>
#include <cstddef>

namespace stepik {
    template<class Type>
    class list {
    public:
        typedef Type value_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
    private:
        template<class Type_>
        struct node {
            Type_ value;
            node* next;
            node* prev;

            node(const Type_& value, node<Type_>* next, node<Type_>* prev)
                    : value(value), next(next), prev(prev) {
            }
        };

    public:
        template<class Type_>
        class list_iterator {
        public:
            typedef ptrdiff_t difference_type;
            typedef Type_ value_type;
            typedef Type_* pointer;
            typedef Type_& reference;
            typedef size_t size_type;
            typedef std::forward_iterator_tag iterator_category;

            list_iterator()
                    : m_node(NULL) {
            }

            list_iterator(const list_iterator& other)
                    : m_node(other.m_node) {
            }

            list_iterator& operator=(const list_iterator& other) {
                m_node = other.m_node;
                return *this;
            }

            bool operator==(const list_iterator& other) const {
                return m_node == other.m_node;
            }

            bool operator!=(const list_iterator& other) const {
                return m_node != other.m_node;
            }

            reference operator*() {
                return m_node->value;
            }

            pointer operator->() {
                return &m_node->value;
            }

            list_iterator& operator++() {
                m_node = m_node->next;
                return *this;
            }

            list_iterator operator++(int) {
                m_node = m_node->next;
                return *this;
            }

            list_iterator(node<Type_>* p)
                    : m_node(p) {
            }

        private:
            friend class list<Type>;

            node<Type_>* m_node;
        };

        typedef list_iterator<Type> iterator;

        iterator begin() {
            return iterator(m_head);
        }

        iterator end() {
            return iterator();
        }

        list()
                : m_head(nullptr), m_tail(nullptr) {
        }

        ~list() {
            clear();
        }

        list(const list& other) {
            auto list_copy = new list();
            auto temp = other.m_head;
            while(temp != nullptr) {
                list_copy->push_back(temp->value);
                temp = temp->next;
            }
            m_head = list_copy->m_head;
            m_tail = list_copy->m_tail;
        }

        list(list&& other) noexcept : m_head(other.m_head), m_tail(other.m_tail) {
            other.m_head = nullptr;
            other.m_tail = nullptr;
        }

        list& operator=(const list& other) {
            if(this != &other) {
                clear();
                auto list_copy = new list(other);
                m_head = list_copy->m_head;
                m_tail = list_copy->m_tail;
            }
            return *this;
        }


        void push_back(const value_type& value) {
            auto node_insert = new node<value_type>(value, nullptr, m_tail);
            if(m_tail != nullptr) {
                m_tail->next = node_insert;
            }
            m_tail = node_insert;
            if(m_head == nullptr) {
                m_head = node_insert;
            }
        }

        void push_front(const value_type& value) {
            auto node_insert = new node<value_type>(value, m_head, m_tail);
            if(m_head != nullptr) {
                m_head->prev = node_insert;
            }
            m_head = node_insert;
            if(!m_tail) {
                m_tail = node_insert;
            }
        }

        iterator insert(iterator pos, const Type& value) {
            auto node_to_insert = new node<value_type>(value, pos.m_node, pos.m_node->prev);
            if(begin() == pos) {
                m_head = node_to_insert;
            } else {
                pos.m_node->prev->next = node_to_insert;
            }
            pos.m_node->prev = node_to_insert;
            pos.m_node = node_to_insert;

            return pos;
        }

        iterator erase(iterator pos) {
            if(pos.m_node != nullptr) {
                if(pos.m_node == m_head) {
                    pop_front();
                    pos.m_node = m_head;
                } else if(pos.m_node == m_tail) {
                    pop_back();
                    pos = end();
                } else {
                    pos.m_node->prev->next = pos.m_node->next;
                    pos.m_node->next->prev = pos.m_node->prev;
                    auto node_to_delete = pos.m_node;
                    pos.m_node = pos.m_node->next;
                    delete node_to_delete;
                }
                return pos;
            }

            return this->end();
        }

        reference front() {
            return m_head->value;
        }

        const_reference front() const {
            return m_head->value;
        }

        reference back() {
            return m_tail->value;
        }

        const_reference back() const {
            return m_tail->value;
        }

        void pop_front() {
            if(m_head != nullptr) {
                auto node_after_head = m_head->next;
                delete[] m_head;
                m_head = node_after_head;
                if(m_head != nullptr) {
                    m_head->prev = nullptr;
                } else {
                    m_tail = nullptr;
                }
            }
        }

        void pop_back() {
            if(m_tail != nullptr) {
                auto node_before_tail = m_tail->prev;
                delete[] m_tail;
                m_tail = node_before_tail;
                if(m_tail != nullptr) {
                    m_tail->next = nullptr;
                } else {
                    m_head = nullptr;
                }
            }
        }

        void clear() {
            auto current = m_head;
            while(current != nullptr) {
                auto del = current;
                current = current->next;
                delete del;
            }
        }

        bool empty() const {
            return m_head == nullptr;
        }

        size_t size() const {
            size_t counter = 0;
            node<value_type>* temp = m_head;
            while(temp != nullptr) {
                counter++;
                temp = temp->next;
            }
            return counter;
        }

    private:
        //your private functions
        node<Type>* m_head;
        node<Type>* m_tail;
    };

}// namespace stepik