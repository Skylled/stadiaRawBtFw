// 600d5150  FUN_600d5150  size=44 bytes
// --- callers ---
//   60061c1c FUN_60061c1c
//   60051240 main__60051240
//   6005c07c FUN_6005c07c
// --- callees ---
//   600d5122 FUN_600d5122
//   600d512e FUN_600d512e


undefined1
FUN_600d5150(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  char cVar1;
  undefined1 uVar2;
  undefined4 *local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_18 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  uStack_c = param_4;
  FUN_600d5122(&local_18);
  cVar1 = FUN_600d512e(*param_1,&local_18);
  if (cVar1 == '\0') {
    uVar2 = 0;
    if (-1 < (int)local_18) {
      if ((uint)local_18 >> 0x19 == 0) {
        uVar2 = 0;
      }
      else {
        uVar2 = 1;
      }
    }
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


