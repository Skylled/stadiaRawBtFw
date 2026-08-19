// 600de3b4  FUN_600de3b4  size=42 bytes
// --- callers ---
//   6007dfcc FUN_6007dfcc
//   6007dddc FUN_6007dddc
// --- callees ---
//   6013cf90 thunk_EXT_FUN_0000b5ba


int FUN_600de3b4(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1;
  for (iVar2 = param_2; iVar2 != 0; iVar2 = iVar2 + -1) {
    iVar1 = thunk_EXT_FUN_0000b5ba(iVar1,0,0x208);
    iVar1 = iVar1 + 0x208;
  }
  return param_2 * 0x208 + param_1;
}


