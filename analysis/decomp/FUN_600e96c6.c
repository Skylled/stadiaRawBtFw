// 600e96c6  FUN_600e96c6  size=84 bytes
// --- callers ---
//   600e972c FUN_600e972c
//   600e9bc2 FUN_600e9bc2
//   600e971a FUN_600e971a
//   600e9746 FUN_600e9746
//   600eaf08 FUN_600eaf08
// --- callees ---
//   6010209a FUN_6010209a
//   6008b6a8 bcm__6008b6a8
//   600e9542 FUN_600e9542
//   6013cfb0 thunk_EXT_FUN_0000ac52
//   600e9680 FUN_600e9680


void FUN_600e96c6(undefined4 param_1,int param_2,int param_3,uint param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  undefined1 auStack_a0 [140];
  
  uVar1 = *(uint *)(param_5 + 0x18);
  if ((uVar1 == param_4) && (uVar1 < 0x12)) {
    iVar2 = uVar1 << 1;
    if (param_2 == param_3) {
      FUN_600e9680(auStack_a0,iVar2);
    }
    else {
      FUN_600e9542(auStack_a0,iVar2,param_2,param_4,param_3,uVar1);
    }
    iVar2 = bcm__6008b6a8(param_1,uVar1,auStack_a0,iVar2,param_5);
    if (iVar2 != 0) {
      thunk_EXT_FUN_0000ac52(auStack_a0,uVar1 << 3);
      return;
    }
  }
                    /* WARNING: Subroutine does not return */
  FUN_6010209a();
}


