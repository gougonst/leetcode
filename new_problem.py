import os
import argparse
import textwrap

def create_new_problem(number, name, tree_node):
    folder_path = os.path.join('./', str(number) + '-' + name[0].upper() + name[1:])
    file_path = os.path.join(folder_path, name + '.cpp')
    create_problem_folder(folder_path)
    create_problem_file(file_path, tree_node)

def create_problem_folder(folder_path):
    try:
        os.mkdir(folder_path)
        print(f'Folder \'{folder_path}\' created.')
    except FileExistsError:
        print(f'Folder \'{folder_path}\' already exists.')

def create_problem_file(file_path, tree_node=False):
    include_code = textwrap.dedent('''\
        #include <bits/stdc++.h>
        using namespace std;
    ''')

    tree_node_code = textwrap.dedent('''
        struct TreeNode {
        \tint val;
        \tTreeNode *left;
        \tTreeNode *right;
        \tTreeNode() : val(0), left(nullptr), right(nullptr) {}
        \tTreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        \tTreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
        };
    ''')

    solution_code = textwrap.dedent('''
        class Solution {
        public:
        \t/* implement solution here */
        };

        int main() {
        \tSolution sol = Solution();
        \t/* write test case here */
        \treturn 0;
        }
    ''')

    cpp_code = include_code
    if (tree_node):
        cpp_code += tree_node_code
    cpp_code += solution_code

    with open(file_path, 'w') as file:
        file.write(cpp_code)

    print(f'Folder \'{file_path}\' created.')

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='setup problem folder')

    parser.add_argument('--name', type=str, help='Specify problem name', required=True)
    parser.add_argument('--number', type=int, help='Specify problem number', required=True)
    parser.add_argument('--tree_node', type=bool, help='Generate struct TreeNode', required=False)

    args = parser.parse_args()

    create_new_problem(number=args.number, name=args.name, tree_node=args.tree_node)
