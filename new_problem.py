import os
import argparse

def create_new_problem(number, name):
    folder_path = os.path.join('./', str(number) + '-' + name[0].upper() + name[1:])
    file_path = os.path.join(folder_path, name + '.cpp')
    create_problem_folder(folder_path)
    create_problem_file(file_path)

def create_problem_folder(folder_path):
    try:
        os.mkdir(folder_path)
        print(f'Folder \'{folder_path}\' created.')
    except FileExistsError:
        print(f'Folder \'{folder_path}\' already exists.')

def create_problem_file(file_path):
    cpp_code = '''\
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
\t/* implement solution here */
};

int main() {
\tSolution sol = Solution();
\t/* write test case here */
\treturn 0;
}
    '''

    with open(file_path, 'w') as file:
        file.write(cpp_code)

    print(f'Folder \'{file_path}\' created.')

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='setup problem folder')

    parser.add_argument('--name', type=str, help='Specify problem name', required=True)
    parser.add_argument('--number', type=int, help='Specify problem number', required=True)

    args = parser.parse_args()

    create_new_problem(number=args.number, name=args.name)
