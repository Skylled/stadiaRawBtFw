// 6005fa0c  flash_lut__6005fa0c  size=102 bytes
// src: flash_lut.cc
// --- callers ---
//   600d48d8 FUN_600d48d8
// --- callees ---
//   6013d150 thunk_EXT_FUN_00000b1c
//   6013d178 thunk_EXT_FUN_00008996
//   6013cf40 thunk_EXT_FUN_00007d10
//   6010165c FUN_6010165c
//   6013d3d8 thunk_EXT_FUN_0000b4c2


/* src: flash_lut.cc */

undefined4 flash_lut__6005fa0c(int param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar1 = param_2 / *(uint *)(param_1 + 4);
  if (param_2 == *(uint *)(param_1 + 4) * uVar1) {
    if (uVar1 <= *(uint *)(param_1 + 8)) {
      thunk_EXT_FUN_0000b4c2(param_1 + 0x1c);
      if (*(char *)(param_1 + 0x19) == '\0') {
        uVar2 = 9;
      }
      else {
        thunk_EXT_FUN_00000b1c(param_2,*(undefined4 *)(param_1 + 4));
        uVar2 = thunk_EXT_FUN_00008996();
      }
      thunk_EXT_FUN_00007d10(param_1 + 0x1c);
      return uVar2;
    }
    uVar2 = 0x198;
    uVar3 = DAT_6005fa7c;
  }
  else {
    uVar2 = 0x193;
    uVar3 = DAT_6005fa74;
    uVar1 = param_2;
  }
  FUN_6010165c(0x28,DAT_6005fa78,uVar2,uVar3,uVar1,param_2);
  return 3;
}


