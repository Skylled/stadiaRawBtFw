// 6010149c  FUN_6010149c  size=46 bytes
// --- callers ---
// --- callees ---
//   601013d0 FUN_601013d0
//   600caab0 FUN_600caab0


void FUN_6010149c(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uStack_14;
  undefined4 uStack_10;
  
  iVar3 = param_1;
  uStack_14 = param_2;
  uStack_10 = param_3;
  FUN_600cbd68();
  do {
    uStack_14 = 0;
    iVar1 = FUN_600caab0(0,0,&uStack_14,0xffffffff,iVar3);
    if (iVar1 == 1) {
      uVar2 = uStack_14 & 0xff;
    }
    else {
      uVar2 = 0;
    }
    FUN_601013d0(param_1 + 0x60,uVar2);
  } while( true );
}


