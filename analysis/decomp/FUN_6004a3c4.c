// 6004a3c4  FUN_6004a3c4  size=94 bytes
// --- callers ---
//   60049a4a FUN_60049a4a
// --- callees ---
//   6004a82e FUN_6004a82e
//   6004bff4 thunk_FUN_6007d978
//   6004bfbc thunk_FUN_600dd822
//   6004a4e6 FUN_6004a4e6


void FUN_6004a3c4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  *(int *)(param_1 + 0x134c) = *(int *)(param_1 + 0x134c) + 1;
  if (*(char *)(param_1 + 5) != '\0') {
    if (*(char *)(param_1 + 4) == '\0') {
      *(undefined1 *)(param_1 + 4) = 1;
      thunk_FUN_6007d978(param_1 + 0xc);
    }
    FUN_6004a82e(param_1 + 0xc);
    thunk_FUN_600dd822(&local_24,param_2,0);
    FUN_6004a4e6(param_1 + 0x88,local_24,uStack_20,uStack_1c,param_3,param_1 + 0x58,param_4);
  }
  return;
}


