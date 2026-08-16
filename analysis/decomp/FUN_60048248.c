// 60048248  FUN_60048248  size=82 bytes
// --- callers ---
// --- callees ---
//   600473e4 queue__600473e4
//   60047f50 FUN_60047f50
//   6004c084 thunk_FUN_601016a2
//   60047290 queue__60047290


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_60048248(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  undefined4 uStack_1c;
  
  uStack_1c = param_4;
  if (param_1 == 0) {
    iStack_28 = param_1;
    iStack_24 = param_2;
    iStack_20 = param_3;
    thunk_FUN_601016a2(_DAT_600482a0,0x182,_DAT_6004829c);
  }
  piVar1 = _DAT_600482a4;
  if (*_DAT_600482a4 != 0) {
    iStack_28 = param_2;
    iStack_24 = param_3;
    iStack_20 = param_1;
    if (param_2 < 6) {
      iVar2 = FUN_60047f50();
      if (iVar2 != 2) {
        param_5 = 0;
      }
      queue__60047290(*piVar1,&iStack_28,param_5);
    }
    else {
      queue__600473e4(*_DAT_600482a4,&iStack_28,param_4,0);
    }
  }
  return;
}


