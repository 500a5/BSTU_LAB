import numpy as np
from itertools import combinations_with_replacement
from itertools import permutations
from math import log2


class Node(object):
    def __init__(self, f_data=None, i_data=None, char=''):
        self.i_data = i_data
        self.f_data = f_data
        self.char = char
        self.left_child = None
        self.right_child = None


class Tree(object):
    def __init__(self, data='', node=None):
        if node is None:
            self.root = Node(data)
        else:
            self.root = node
        self.branches_list = []
        self.branches_dict = {}

    def in_order(self, local_root, deep, like_dict, last_char='', s=''):
        if local_root is not None:
            s += local_root.f_data
            self.in_order(local_root.left_child, deep + 1, like_dict, last_char=local_root.char, s=s)
            self.in_order(local_root.right_child, deep + 1, like_dict, last_char=local_root.char, s=s)
        else:
            if like_dict:
                self.branches_dict.update({last_char: s})
            else:
                if len(self.branches_list) == 0 or self.branches_list[-1] != s:
                    self.branches_list.append(s)

    def get_all_branches(self, like_dict=False, chars=None):
        self.branches_list = []
        self.in_order(self.root, 0, like_dict=like_dict)
        if like_dict:
            for char in chars:
                self.branches_list.append(self.branches_dict[char])
        return self.branches_list

    def in_order_(self, local_root, deep, mode):
        if local_root is not None:
            self.in_order_(local_root.right_child, deep + 1, mode)
            if mode == 0:
                print(str("  "*deep), local_root.i_data)
            elif mode == 1:
                print(str("  " * deep), local_root.i_data, local_root.f_data)
            self.in_order_(local_root.left_child, deep + 1, mode)

    def display_tree(self, mode=1):
        print("\n\n")
        self.in_order_(self.root, 0, mode)


class PriorityQueue(object):
    def __init__(self, size=0):
        self.__size = size
        self.__queue = list(Node(-1, -1, '') for _ in range(size))
        self.__n_items = 0

    def get_size(self):
        return self.__n_items

    @staticmethod
    def compare(item_1, item_2):
        if item_1.char != '':
            return item_1.i_data > item_2.i_data and item_1.char > item_2.char
        else:
            return item_1.i_data > item_2.i_data

    def insert(self, item):
        if self.__n_items == 0:
            self.__queue[self.__n_items] = item
            self.__n_items += 1
        else:
            j = self.__n_items - 1
            while j >= 0:
                if self.compare(item, self.__queue[j]):
                    self.__queue[j + 1] = self.__queue[j]
                else:
                    break
                j -= 1
            self.__queue[j + 1] = item
            self.__n_items += 1
        self.__queue = sorted(self.__queue, key=lambda item: (-item.i_data, item.char))

    def display(self):
        a = ''
        for x in self.__queue[:self.__n_items]:
            a += f'{x.i_data} | '
        print(a, '\n\n')

    def remove(self):
        self.__n_items -= 1
        return self.__queue[self.__n_items]

    def peek_min(self):
        return self.__queue[self.__n_items - 1]

    def is_empty(self):
        return self.__n_items == 0

    def is_full(self):
        return self.__n_items == self.__size


class Haffman:
    def __init__(self, blocks=1):
        self.blocks = blocks
        self.a, self.ps = self.get_ps()
        if blocks != 1:
            self.a, self.ps = self.multiblock(blocks)
        self.nodes = self.make_nodes()
        self.queue_nodes = PriorityQueue(len(self.nodes))
        for node in self.nodes:
            self.queue_nodes.insert(node)
        self.tree = self.get_tree(self.queue_nodes)
        self.codes = self.tree.get_all_branches(like_dict=True, chars=self.a)
        self.a_dict = {}
        self.codes_dict = {}
        for a_i, bi_code in zip(self.a, self.codes):
            self.a_dict.update({a_i: bi_code})
            self.codes_dict.update({bi_code: a_i})

    def coder(self, mess):
        answer = ''
        while mess != '':
            flag = True
            for symbol, bi_code in self.a_dict.items():
                if mess.startswith(symbol):
                    answer += bi_code
                    mess = mess[len(symbol):]
                    flag = False
                    break
            if flag:
                return "It's message is not correct"
        return answer

    def decoder(self, bi_code):
        answer = ''
        while bi_code != '':
            flag = True
            for de_code, symbol in self.codes_dict.items():
                if bi_code.startswith(de_code):
                    answer += symbol
                    bi_code = bi_code[len(de_code):]
                    flag = False
                    break
            if flag:
                return "It's code is not correct"
        return answer

    @staticmethod
    def get_ps():
        # file_name = input('Write name of file with Pairs ai P(ai) = ')
        file_name = "lab_3.txt"
        f = open(file_name, "r")
        tmp = f.read().split('\n')
        f.close()
        tmp_list = []
        for item in tmp:
            tmp_list.append(item.split())
        tmp_list.sort(key=lambda x: -float(x[-1]))
        a = []
        ps = []
        for item in tmp_list:
            a.append(item[0])
            ps.append(float(item[-1]))
        pairs = list(zip(a, ps))
        pairs = sorted(pairs, key=lambda pair: (-pair[-1], pair[0]))
        a = []
        ps = []
        for a_i, p_i in pairs:
            a.append(a_i)
            ps.append(p_i)

        return np.array(a), np.array(ps)

    def make_nodes(self):
        array = [Node(char, p, char) for char, p in zip(self.a, self.ps)]
        return array

    @staticmethod
    def get_tree(queue):
        while queue.get_size() > 1:
            new_left = queue.remove()
            new_left.f_data = '1'
            new_right = queue.remove()
            new_right.f_data = '0'
            new_node = Node('', new_left.i_data + new_right.i_data, new_left.char + new_right.char)
            new_node.left_child = new_left
            new_node.right_child = new_right
            queue.insert(new_node)
        return Tree(node=queue.remove())

    def get_middle_len(self):
        return round(sum(self.ps * np.array(list(map(lambda x: len(x), self.codes))))/self.blocks, 6)

    def multiblock(self, blocks):
        a = []
        ps = []
        for comb in combinations_with_replacement(self.a, blocks):
            for perm in permutations(comb):
                perm = ''.join(perm)
                if perm not in a:
                    a.append(perm)
                    p = 1
                    for char in perm:
                        p *= self.ps[self.a == char][-1]
                    ps.append(round(p, 6))
        pairs = list(zip(a, ps))
        pairs = sorted(pairs, key=lambda pair: (-pair[-1], pair[0]))
        a = []
        ps = []
        for a_i, p_i in pairs:
            a.append(a_i)
            ps.append(p_i)
        return a, ps


class ShenonPhano:
    def __init__(self, blocks=1):
        self.a, self.ps = self.get_ps()
        self.blocks = blocks
        if blocks != 1:
            self.a, self.ps = self.multiblock(blocks)
        self.codes_tree = self.get_codes()
        self.codes = self.codes_tree.get_all_branches()
        self.a_dict = {}
        self.codes_dict = {}
        for a_i, bi_code in zip(self.a, self.codes):
            self.a_dict.update({a_i: bi_code})
            self.codes_dict.update({bi_code: a_i})

    def get_middle_len(self):
        return round(sum(self.ps * np.array(list(map(lambda x: len(x), self.codes))))/self.blocks, 6)

    def multiblock(self, blocks):
        a = []
        ps = []
        for comb in combinations_with_replacement(self.a, blocks):
            for perm in permutations(comb):
                perm = ''.join(perm)
                if perm not in a:
                    a.append(perm)
                    p = 1
                    for char in perm:
                        p *= self.ps[self.a == char][-1]
                    ps.append(round(p, 6))
        pairs = list(zip(a, ps))
        pairs = sorted(pairs, key=lambda pair: (-pair[-1], pair[0]))
        a = []
        ps = []
        for a_i, p_i in pairs:
            a.append(a_i)
            ps.append(p_i)
        return a, ps

    def coder(self, mess):
        answer = ''
        while mess != '':
            flag = True
            for symbol, bi_code in self.a_dict.items():
                if mess.startswith(symbol):
                    answer += bi_code
                    mess = mess[len(symbol):]
                    flag = False
                    break
            if flag:
                return "It's message is not correct"
        return answer

    def decoder(self, bi_code):
        answer = ''
        while bi_code != '':
            flag = True
            for de_code, symbol in self.codes_dict.items():
                if bi_code.startswith(de_code):
                    answer += symbol
                    bi_code = bi_code[len(de_code):]
                    flag = False
                    break
            if flag:
                return "It's code is not correct"
        return answer

    @staticmethod
    def get_code(ps, symbol):
        local_root = Node(symbol)
        if len(ps) == 1:
            return local_root
        min_diff = 10
        min_index = 0
        for index in range(1, len(ps)):
            diff = abs(sum(ps[: index]) - sum(ps[index:]))
            if diff < min_diff:
                min_index = index
                min_diff = diff
        local_root.left_child = ShenonPhano.get_code(ps[:min_index], '0')
        local_root.right_child = ShenonPhano.get_code(ps[min_index:], '1')
        return local_root

    def get_codes(self):
        root = self.get_code(self.ps, '')
        return Tree(node=root)

    @staticmethod
    def get_ps():
        # file_name = input('Write name of file with Pairs ai P(ai) = ')
        file_name = "lab_3.txt"
        f = open(file_name, "r")
        tmp = f.read().split('\n')
        f.close()
        tmp_list = []
        for item in tmp:
            tmp_list.append(item.split())
        tmp_list.sort(key=lambda x: -float(x[-1]))
        a = []
        ps = []
        for item in tmp_list:
            a.append(item[0])
            ps.append(float(item[-1]))
        pairs = list(zip(a, ps))
        pairs = sorted(pairs, key=lambda pair: (-pair[-1], pair[0]))
        a = []
        ps = []
        for a_i, p_i in pairs:
            a.append(a_i)
            ps.append(p_i)

        return np.array(a), np.array(ps)


class Task3:
    def __init__(self):
        a = ShenonPhano(blocks=1)
        message = 'BBCCCAADCACCDCEDAEEA'
        code = a.coder(message)
        decode = a.decoder(code)
        middle_len_1 = a.get_middle_len()

        print('Not Bigrams: ')
        print('Message: ', message)
        print('Dict: ', a.a_dict)
        print('Code: ', code)
        print('Decode: ', decode)
        print('Message == Decode: ', message == decode)
        print('f(a) = ', middle_len_1)
        for a_i, p_i, code in zip(a.a, a.ps, a.codes):
            print(f'{a_i} | {p_i} | {code}')
        print(f'H = {-sum([x * log2(x) for x in a.ps])}')
        print('='*80)
        a = ShenonPhano(blocks=2)
        message = 'BBCCCAADCACCDCEDAEEA'
        code = a.coder(message)
        decode = a.decoder(code)
        middle_len_2 = a.get_middle_len()
        print('Bigrams: ')
        print('Message: ', message)
        print('Dict: ', a.a_dict)
        print('Code: ', code)
        print('Decode: ', decode)
        print('Message == Decode: ', message == decode)
        print('f(a) = ', middle_len_2)
        for a_i, p_i, code in zip(a.a, a.ps, a.codes):
            print(f'{a_i} | {p_i} | {code}')
        print(f'H = {-sum([x * log2(x) for x in a.ps])}')
        print('='*80)


class Task4:
    def __init__(self):
        a = Haffman(blocks=1)
        message = 'BBCCCAADCACCDCEDAEEA'
        code = a.coder(message)
        decode = a.decoder(code)
        middle_len_1 = a.get_middle_len()

        print('Message: ', message)
        print('Dict: ', a.a_dict)
        print('Code: ', code)
        print('Decode: ', decode)
        print('Message == Decode: ', message == decode)
        print('f(a) = ', middle_len_1)
        for a_i, p_i, code in zip(a.a, a.ps, a.codes):
            print(f'{a_i} | {p_i} | {code}')
        print(f'H = {-sum([x * log2(x) for x in a.ps])}')
        print('='*80)

        a = Haffman(blocks=2)
        message = 'BBCCCAADCACCDCEDAEEA'
        code = a.coder(message)
        decode = a.decoder(code)
        middle_len_1 = a.get_middle_len()
        print('Bigrams: ')
        print('Message: ', message)
        print('Dict: ', a.a_dict)
        print('Code: ', code)
        print('Decode: ', decode)
        print('Message == Decode: ', message == decode)
        print('f(a) = ', middle_len_1)
        for a_i, p_i, code in zip(a.a, a.ps, a.codes):
            print(f'{a_i} | {p_i} | {code}')
        print(f'H = {-sum([x * log2(x) for x in a.ps])}')
        print('='*80)


if __name__ == '__main__':
    #Task3()
    Task4()
