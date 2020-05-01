#include <iostream>
using namespace std;


int count_blank_by_row(int sudo[3][3][3][3], int idx1, int idx2);
int count_blank_by_column(int sudo[3][3][3][3], int idx1, int idx2);
int count_blank_by_box(int sudo[3][3][3][3], int idx1, int idx2);
int find_missing_by_row(int sudo[3][3][3][3], int idx1, int idx2);
int find_missing_by_column(int sudo[3][3][3][3], int idx1, int idx2);
int find_missing_by_box(int sudo[3][3][3][3], int idx1, int idx2);
void show_sudo(int sudo[3][3][3][3]);
int is_solved(int sudo[3][3][3][3]);
int solve_missing_one_by_row(int sudo[3][3][3][3], int val, int idx1, int idx2);
int solve_missing_one_by_column(int sudo[3][3][3][3], int val, int idx1, int idx2);
int solve_missing_one_by_box(int sudo[3][3][3][3], int val, int idx1, int idx2);
void solve_by_missing(int sudo[3][3][3][3]);
int find_in_row(int sudo[3][3][3][3], int val, int idx1, int idx2);
int find_in_column(int sudo[3][3][3][3], int val, int idx1, int idx2);
int find_in_box(int sudo[3][3][3][3], int val, int idx1, int idx2);
void block_by_row(int val, int idx1, int idx2);
void block_by_column(int val, int idx1, int idx2);
void block_by_box(int val, int idx1, int idx2);
void copy_sudo(int sudo[3][3][3][3]);
void block(int sudo[3][3][3][3], int val);
void solve_from_temp(int sudo[3][3][3][3], int val);
int temp_solved();
int sudo_solved(int sudo[3][3][3][3]);
int solve_blank_by_row(int sudo[3][3][3][3], int val, int idx1, int idx2);
int solve_blank_by_column(int sudo[3][3][3][3], int val, int idx1, int idx2);
int solve_blank_by_box(int sudo[3][3][3][3], int val, int idx1, int idx2);
void solve(int sudo[3][3][3][3]);


int swap_count = 0;
int last_swap_count = 0;
int temp[3][3][3][3];

int main(){
  int sudo[3][3][3][3] = {{{{0,0,0},  {0,0,0},  {0,4,0}},\
                           {{2,5,0},  {3,7,4},  {0,0,0}},\
                           {{7,0,0},  {0,0,0},  {0,0,1}}},\

                          {{{0,3,0},  {2,0,0},  {1,0,8}},\
                           {{0,6,2},  {0,0,1},  {0,5,7}},\
                           {{0,7,0},  {5,0,0},  {6,0,4}}},\

                          {{{8,0,0},  {0,0,0},  {0,0,5}},\
                           {{3,9,0},  {8,1,5},  {0,0,0}},\
                           {{0,0,0},  {0,0,0},  {0,8,0}}}};

  show_sudo(sudo);
  copy_sudo(sudo);

  // block(sudo, 1);
  // show_sudo(temp);
  // solve_from_temp(sudo, 1);
  // solve_blank_by_box(sudo, )

  solve(sudo);
  show_sudo(sudo);
}


int count_blank_by_column(int sudo[3][3][3][3], int idx1, int idx2){
  int count = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        for(int l = 0; l < 3; l++){
          if(k == idx1 && l == idx2 && sudo[i][j][k][l] == 0){
            count++;
          }
        }
      }
    }
  }
  return count;
}


int count_blank_by_row(int sudo[3][3][3][3], int idx1, int idx2){
  int count = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        for(int l = 0; l < 3; l++){
          if(i == idx1 && j == idx2 && sudo[i][j][k][l] == 0){
            count++;
          }
        }
      }
    }
  }
  return count;
}


int count_blank_by_box(int sudo[3][3][3][3], int idx1, int idx2){
  int count = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        for(int l = 0; l < 3; l++){
          if(i == idx1 && k == idx2 && sudo[i][j][k][l] == 0){
            count++;
          }
        }
      }
    }
  }
  return count;
}




void show_sudo(int sudo[3][3][3][3]){
  cout << endl;
  // cout << "\t_______________________________________" << endl << endl;
  cout << "\t=======================================" << endl;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      cout << "\t";
      for(int k = 0; k < 3; k++){
        cout << "|  ";
        for(int l = 0; l < 3; l++){
          cout << sudo[i][j][k][l] << "  ";
        }
        cout << "|";
      }
      cout << endl;
    }
    cout << "\t=======================================" << endl;
    // cout << "\t_______________________________________" << endl << endl;
  }
  cout << endl;
}


int find_missing(int sudo[3][3]){
  int temp[9] = {1,2,3,4,5,6,7,8,9};
  int ret = 0;
  for(int i = 0; i < 9; i++){
    ret = 0;
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        if(temp[i] == sudo[j][k]){
          ret++;
        }
      }
    }
    if(ret == 0){
      return temp[i];
    }
  }
  return 0;
}


int find_missing_by_row(int sudo[3][3][3][3], int idx1, int idx2){
  int temp[9] = {1,2,3,4,5,6,7,8,9};
  int ret= 0;
  for(int a = 0; a < 9; a++){
    ret = 0;
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          for(int l = 0; l < 3; l++){
            if(i == idx1 && j == idx2){
              if(temp[a] == sudo[i][j][k][l]) ret++;
            }
          }
        }
      }
    }
    if(ret == 0)
      return temp[a];
  }
  return 0;
}


int find_missing_by_column(int sudo[3][3][3][3], int idx1, int idx2){
  int temp[9] = {1,2,3,4,5,6,7,8,9};
  int ret= 0;
  for(int a = 0; a < 9; a++){
    ret = 0;
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          for(int l = 0; l < 3; l++){
            if(k == idx1 && l == idx2){
              if(temp[a] == sudo[i][j][k][l]) ret++;
            }
          }
        }
      }
    }
    if(ret == 0)
      return temp[a];
  }
  return 0;
}


int find_missing_by_box(int sudo[3][3][3][3], int idx1, int idx2){
  int temp[9] = {1,2,3,4,5,6,7,8,9};
  int ret= 0;
  for(int a = 0; a < 9; a++){
    ret = 0;
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          for(int l = 0; l < 3; l++){
            if(i == idx1 && k == idx2){
              if(temp[a] == sudo[i][j][k][l]) ret++;
            }
          }
        }
      }
    }
    if(ret == 0)
      return temp[a];
  }
  return 0;
}

int is_solved(int sudo[3][3][3][3]){
  int count = 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        for(int l = 0; l < 3; l++){
          if(sudo[i][j][k][l] != 0)
          count ++;
        }
      }
    }
  }
  if(count == 81) return 1;
  return 0;
}

int solve_missing_one_by_box(int sudo[3][3][3][3], int val, int idx1, int idx2){
  if(find_in_box(sudo, val, idx1, idx1)) return 0;
  for(int a = 0; a < 9; a++){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          for(int l = 0; l < 3; l++){
            if(i == idx1 && k == idx2){
              if(sudo[i][j][k][l] == 0) sudo[i][j][k][l] = val;
            }
          }
        }
      }
    }
  }
  return 0;
}
int solve_missing_one_by_row(int sudo[3][3][3][3], int val, int idx1, int idx2){
    if(find_in_row(sudo, val, idx1, idx1)) return 0;
  for(int a = 0; a < 9; a++){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          for(int l = 0; l < 3; l++){
            if(i == idx1 && j == idx2){
              if(sudo[i][j][k][l] == 0) sudo[i][j][k][l] = val;
            }
          }
        }
      }
    }
  }
  return 0;
}
int solve_missing_one_by_column(int sudo[3][3][3][3], int val, int idx1, int idx2){
    if(find_in_column(sudo, val, idx1, idx1)) return 0;
  for(int a = 0; a < 9; a++){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          for(int l = 0; l < 3; l++){
            if(k == idx1 && l == idx2){
              if(sudo[i][j][k][l] == 0) sudo[i][j][k][l] = val;
            }
          }
        }
      }
    }
  }
  return 0;
}


void solve_by_missing(int sudo[3][3][3][3]){
  while(!sudo_solved(sudo)){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        if(count_blank_by_row(sudo, i, j) == 1){
          solve_missing_one_by_row(sudo, find_missing_by_row(sudo, i, j), i, j);
        }
        if(count_blank_by_column(sudo, i, j) == 1){
          solve_missing_one_by_column(sudo, find_missing_by_column(sudo, i, j), i, j);
        }
        if(count_blank_by_box(sudo, i, j) == 1){
          solve_missing_one_by_box(sudo, find_missing_by_box(sudo, i, j), i, j);
        }
      }
    }
  }
}

int find_in_column(int sudo[3][3][3][3], int val, int idx1, int idx2){
  for(int a = 0; a < 9; a++){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          for(int l = 0; l < 3; l++){
            if(k == idx1 && l == idx2){
              if(sudo[i][j][k][l] == val) return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}
int find_in_row(int sudo[3][3][3][3], int val, int idx1, int idx2){
  for(int a = 0; a < 9; a++){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          for(int l = 0; l < 3; l++){
            if(i == idx1 && j == idx2){
              if(sudo[i][j][k][l] == val) return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}
int find_in_box(int sudo[3][3][3][3], int val, int idx1, int idx2){
  for(int a = 0; a < 9; a++){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          for(int l = 0; l < 3; l++){
            if(i == idx1 && k == idx2){
              if(sudo[i][j][k][l] == val) return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}

void copy_sudo(int sudo[3][3][3][3]){
  for(int a = 0; a < 9; a++){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          for(int l = 0; l < 3; l++){
            temp[i][j][k][l] = sudo[i][j][k][l];
          }
        }
      }
    }
  }

}

void block_by_row(int val, int idx1, int idx2){
  for(int a = 0; a < 9; a++){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          for(int l = 0; l < 3; l++){
            if(i == idx1 && j == idx2){
              if(temp[i][j][k][l] == 0) temp[i][j][k][l] = val+10;
            }
          }
        }
      }
    }
  }
}
void block_by_column(int val, int idx1, int idx2){
  for(int a = 0; a < 9; a++){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          for(int l = 0; l < 3; l++){
            if(k == idx1 && l == idx2){
              if(temp[i][j][k][l] == 0) temp[i][j][k][l] = val+10;
            }
          }
        }
      }
    }
  }
}
void block_by_box(int val, int idx1, int idx2){
  for(int a = 0; a < 9; a++){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        for(int k = 0; k < 3; k++){
          for(int l = 0; l < 3; l++){
            if(i == idx1 && k == idx2){
              if(temp[i][j][k][l] == 0) temp[i][j][k][l] = val+10;
            }
          }
        }
      }
    }
  }
}

void block(int sudo[3][3][3][3], int val){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(find_in_row(sudo, val, i, j)){
        block_by_row(val,  i, j);
      }
      if(find_in_column(sudo, val, i, j)){
        block_by_column(val, i, j);
      }
      if(find_in_box(sudo, val, i, j)){
        block_by_box(val, i, j);
      }
    }
  }
}

void solve_from_temp(int sudo[3][3][3][3], int val){
  while(!temp_solved()){
    for(int i = 0; i < 3; i++){
      for(int j = 0; j < 3; j++){
        // if(count_blank_by_row(temp, i, j) == 1){
        //   solve_blank_by_row(sudo, val, i, j);
        // }
        // if(count_blank_by_column(temp, i, j) == 1){
        //   solve_blank_by_column(sudo, val, i, j);
        // }
        if(count_blank_by_box(temp, i, j) == 1){
          solve_blank_by_box(sudo, val, i, j);
        }
      }
    }
  }
}

int temp_solved(){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      // if(count_blank_by_row(temp, i, j) == 1) return 0;
      // if(count_blank_by_column(temp, i, j) == 1) return 0;
      if(count_blank_by_box(temp, i, j) == 1) return 0;
    }
  }
  return 1;
}
int sudo_solved(int sudo[3][3][3][3]){
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      if(count_blank_by_row(sudo, i, j) == 1) return 0;
      if(count_blank_by_column(sudo, i, j) == 1) return 0;
      if(count_blank_by_box(sudo, i, j) == 1) return 0;
    }
  }
  return 1;
}

int solve_blank_by_row(int sudo[3][3][3][3], int val, int idx1, int idx2){
  // if(find_in_row(temp, val, idx1, idx1)) return 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        for(int l = 0; l < 3; l++){
          if(i == idx1 && j == idx2){
            if(temp[i][j][k][l] == 0){
              sudo[i][j][k][l] = val;
              temp[i][j][k][l] = val;
              swap_count++;
            }
          }
        }
      }
    }
  }
  return 0;
}
int solve_blank_by_column(int sudo[3][3][3][3], int val, int idx1, int idx2){
  // if(find_in_column(temp, val, idx1, idx1)) return 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        for(int l = 0; l < 3; l++){
          if(k == idx1 && l == idx2){
            if(temp[i][j][k][l] == 0){
              sudo[i][j][k][l] = val;
              temp[i][j][k][l] = val;
              swap_count++;
            }
          }
        }
      }
    }
  }
  return 0;
}
int solve_blank_by_box(int sudo[3][3][3][3], int val, int idx1, int idx2){
  // if(find_in_box(temp, val, idx1, idx1)) return 0;
  for(int i = 0; i < 3; i++){
    for(int j = 0; j < 3; j++){
      for(int k = 0; k < 3; k++){
        for(int l = 0; l < 3; l++){
          if(i == idx1 && k == idx2){
            if(temp[i][j][k][l] == 0){
              sudo[i][j][k][l] = val;
              temp[i][j][k][l] = val;
              swap_count++;
            }
          }
        }
      }
    }
  }
  return 0;
}

void solve(int sudo[3][3][3][3]){
  int count = 0;
  while(!is_solved(sudo)){
    count++;
    for(int i = 1; i <= 9; i++){
      copy_sudo(sudo);
      block(sudo, i);
      solve_from_temp(sudo, i);
    }
    if(count == 100) break;
  }
  // solve_by_missing(sudo);
}
