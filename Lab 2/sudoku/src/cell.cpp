#include <sudoku/cell.h>
#include <sudoku/grid.h>
#include <numeric>
#include <iostream>
#include <algorithm>
#include <vector>

void Cell::init(uint row, uint col, std::array<Cell, 81> &grid, uint digit)
{
  if(digit)
  {
    this->digit_ = digit;
    // no candidates, we know this one
  }
  else
  {
    candidates_.resize(9);
    std::iota(candidates_.begin(), candidates_.end(), 1);
  }

  const auto cellPtr = [&grid](uint row, uint col) -> Cell*
  {return grid.data() + 9*row + col;};

  // register neighboors
  const uint quad_row = 3*(row/3);
  const uint quad_col = 3*(col/3);
  auto nb{neighboors_.begin()};
  for(uint ax = 0; ax < 9; ++ax)
  {
    // same colum, different row
    if(ax != row)
      *(nb++) = cellPtr(ax,col);
    // same row, different column
    if(ax != col)
      *(nb++) = cellPtr(row, ax);
    // same 3x3 sub-square
    const uint r = quad_row + ax / 3;
    const uint c = quad_col + ax % 3;
    if(r != row && c != col)
      *(nb++) = cellPtr(r, c);
  }
}


// TODO section

void Cell::prune(uint guess){

    // The cell does not have a digit yet
    if(!digit_){

        // Find the guess in the candidates list
        auto guess_index = find(candidates_.begin(),candidates_.end(),guess); // If guess is not in the list, the index will be the length of the vector

        // Guess is present in the candidates list
        if(guess_index != candidates_.end()){
            candidates_.erase(guess_index);
            pruned_count_[guess]++;
        }
        else{ // not present = already pruned
            return;
        }
    }
}

void Cell::restore(uint guess)
{
    // The cell does not have a digit yet
    if(!digit_ and pruned_count_[guess] > 0){
        pruned_count_[guess]--;
    }
    else{
        return;
    }
    if(pruned_count_[guess] == 0){
        candidates_.insert(candidates_.end()+1,guess);
        sort(candidates_.begin(),candidates_.end());
    }
}

void Cell::set(uint guess){
    digit_ = guess;

    for(int i=0;i < neighboors_.size(); i++){
        neighboors_[i]->prune(guess);
    }
}

void Cell::cancel(){
    auto guess = digit_;
    digit_ = 0;
    for(int i=0;i < neighboors_.size(); i++){
        neighboors_[i]->restore(guess);
    }
}
