// 600fde0c  FUN_600fde0c  size=136 bytes
// --- callers ---
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba
//   600efcc6 FUN_600efcc6


void FUN_600fde0c(int param_1,int param_2)

{
  undefined1 local_2b8 [2];
  undefined2 local_2b6;
  undefined1 local_2b4;
  undefined1 auStack_2b3 [7];
  undefined2 local_2ac;
  
  if (**(int **)(param_1 + 0xc) != 0) {
    thunk_EXT_FUN_0000b5ba(local_2b8,0,0x2b0);
    local_2b4 = *(undefined1 *)(*(int *)(param_1 + 0xc) + 5);
    local_2b6 = *(undefined2 *)(param_2 + 6);
    FUN_600efcc6(auStack_2b3,param_1 + 2);
    local_2b8[0] = 0x85;
    local_2ac = 0x101;
    (*(code *)**(undefined4 **)(param_1 + 0xc))(5,local_2b8);
  }
  return;
}


