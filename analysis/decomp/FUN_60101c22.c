// 60101c22  FUN_60101c22  size=38 bytes
// --- callers ---
//   60082aac FUN_60082aac
// --- callees ---
//   6010209a FUN_6010209a
//   6013d248 thunk_EXT_FUN_00008836
//   600cc9c4 FUN_600cc9c4


void FUN_60101c22(int param_1,undefined4 param_2)

{
  int iVar1;
  code *pcVar2;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  while( true ) {
    iVar1 = thunk_EXT_FUN_00008836(param_2,param_1);
    if (iVar1 != 0) {
      return;
    }
    pcVar2 = (code *)FUN_600cc9c4();
    if (pcVar2 == (code *)0x0) break;
    (*pcVar2)();
  }
                    /* WARNING: Subroutine does not return */
  FUN_6010209a();
}


