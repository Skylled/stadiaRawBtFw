// 6005ee88  bee__6005ee88  size=92 bytes
// src: bee.cc
// --- callers ---
//   6005f07c FUN_6005f07c
// --- callees ---
//   6010165c FUN_6010165c
//   6013cf48 thunk_EXT_FUN_000007b8


/* src: bee.cc */

undefined4 bee__6005ee88(uint param_1,uint param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_3 == 0) {
    uVar1 = thunk_EXT_FUN_000007b8(DAT_6005eee4);
    uVar2 = thunk_EXT_FUN_000007b8(DAT_6005eee8);
    uVar3 = DAT_6005eeec;
  }
  else {
    uVar1 = thunk_EXT_FUN_000007b8(DAT_6005eef0);
    uVar2 = thunk_EXT_FUN_000007b8(DAT_6005eef4);
    uVar3 = DAT_6005eef8;
  }
  if ((param_1 < uVar1) || (uVar2 <= param_2)) {
    FUN_6010165c(0x28,DAT_6005ef00,0xb8,DAT_6005eefc,uVar3,param_1,param_2,param_4);
    uVar3 = 9;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


