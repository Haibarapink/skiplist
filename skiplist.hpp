#pragma once

#include <vector>
#include <memory>
#include <optional>
#include <cassert>
#include <random>

namespace haibarapink {
    struct sl_defs {
        constexpr static size_t MAX_LEVEL = 32;
    };

    template<typename key_t, typename val_t>
    struct sl_node {
        using node_type = sl_node<key_t, val_t>;
        using node_ptr = node_type *;

        size_t l;
        key_t k;
        val_t v;

        std::vector<node_ptr> forwards;

        sl_node(size_t level) : l(level), forwards(l, nullptr) {}

        sl_node(key_t key, val_t val, size_t level) : k(key), v(val), l(level), forwards(l, nullptr) {}
    };



    template<typename key_t, typename val_t>
    class skip_list {
        using node_type = sl_node<key_t, val_t>;
        using node_ptr = node_type *;

        static size_t random_level() {
            size_t level = 1;
            while (((double)rand() / (RAND_MAX)) < 0.25 && level < sl_defs::MAX_LEVEL) ++level;
            return level;
        }
    private:
        class iterator {
        public:
            iterator(node_ptr n): cur_(n) {}
            auto operator*() {
                std::pair<const key_t&, const val_t&> res {cur_->k, cur_->v};
                return res;
            }

            iterator operator++() {
                cur_ = cur_->forwards[0];
                return *this;
            }

            bool operator!=(const iterator& other) const {
                return cur_ != other.cur_;
            }

        private:
            node_ptr cur_;
        };


    public:
        skip_list() {
            head_ = {new node_type{sl_defs::MAX_LEVEL}};
        }

        ~skip_list() {
            auto x = head_;
            while (x) {
                auto next = x->forwards[0];
                delete x;
                x = next;
            }
        }

        iterator begin() {
            return iterator{head_->forwards[0]};
        }

        iterator end() {
            return iterator{nullptr};
        }

        std::optional<val_t> search(const key_t &k) const {
            auto n = find(k);
            if (!n) {
                return std::nullopt;
            }
            return n->v;
        }

        void insert(key_t k, val_t v);

        bool erase(const key_t &k);

    private:
        node_ptr find(const key_t &k) const {
            node_ptr x = head_;
            for (int i = l_ - 1; i >= 0; --i) {
                // x→key < searchKey ≤ x→forward[i]→key
                while ((x->forwards[i] != nullptr) && (k > x->forwards[i]->k)) {
                    x = x->forwards[i];
                }
            }

            x = x->forwards[0];
            if (x && x->k == k) {
                return x;
            }
            return nullptr;
        }

    private:
        node_ptr head_;
        size_t l_{1};
        size_t size_{0};
    };

    template<typename key_t, typename val_t>
    inline void skip_list<key_t, val_t>::insert(key_t k, val_t v) {
        std::array<node_ptr, sl_defs::MAX_LEVEL> updates;
        node_ptr x = head_;
        for (int i = l_ - 1; i >= 0; --i) {
            // x→key < searchKey ≤ x→forward[i]→key
            while ((x->forwards[i] != nullptr) && (k > x->forwards[i]->k)) {
                x = x->forwards[i];
            }
            updates[i] = x;
        }


        x = x->forwards[0];
        if (x && x->k == k) {
            x->v = std::move(v);
            return;
        }
        size_++;
        auto level = random_level();
        node_ptr new_node = new node_type{std::move(k), std::move(v), level};
        if (level > l_) {
            level = l_ + 1;
            for (int i = l_; i < level; ++i) {
                updates[i] = head_;
            }
            l_ = level;
        }

        for (int i = 0; i < level; ++i) {
            new_node->forwards[i] = updates[i]->forwards[i];
            updates[i]->forwards[i] = new_node;
        }
    }

    template<typename key_t, typename val_t>
    inline bool skip_list<key_t, val_t>::erase(const key_t &k) {
        std::array<node_ptr, sl_defs::MAX_LEVEL> updates;
        auto x = head_;
        for (int i = l_ - 1; i >= 0; --i) {
            // x→key < searchKey ≤ x→forward[i]→key
            while (x->forwards[i] != nullptr && k > x->forwards[i]->k) {
                x = x->forwards[i];
            }
            updates[i] = x;
        }
        x = x->forwards[0];
        if (!x || x->k != k) {
            return false;
        }
        size_--;
        for (int i = 0; i < l_; ++i) {
            if (updates[i]->forwards[i] != x) {
                break;
            }
            updates[i]->forwards[i] = x->forwards[i];
        }
        delete x;
        while (l_ > 1 && head_->forwards[l_ - 1] == nullptr) {
            l_--;
        }
        return true;
    }

}