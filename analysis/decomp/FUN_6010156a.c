// 6010156a  FUN_6010156a  size=80 bytes
// --- callers ---
//   601015e6 FUN_601015e6
// --- callees ---
//   6010155c FUN_6010155c
//   6013cf90 thunk_EXT_FUN_0000b5ba


undefined4 FUN_6010156a(int *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  while( true ) {
    while( true ) {
      uVar1 = param_1[2];
      uVar2 = param_1[3];
      if (uVar2 <= uVar1) break;
      if (param_2 <= (uVar2 - 1) - uVar1) {
        return 0;
      }
      FUN_6010155c(param_1);
    }
    if (param_2 <= param_1[1] - uVar1) {
      return 0;
    }
    if (uVar1 == uVar2) break;
    thunk_EXT_FUN_0000b5ba(uVar1 + *param_1,0);
    if (param_1[3] == 0) {
      FUN_6010155c(param_1);
    }
    param_1[2] = 0;
  }
  return 8;
}


