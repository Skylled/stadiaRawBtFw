// 6004bd4e  FUN_6004bd4e  size=34 bytes
// --- callers ---
//   600466cc FUN_600466cc
// --- callees ---
//   6004904e heap_5_improved__60048774
//   6004c3d4 thunk_FUN_600cc9c4
//   6004c3ac thunk_FUN_6010209a


void FUN_6004bd4e(int param_1)

{
  int iVar1;
  code *pcVar2;
  
  if (param_1 == 0) {
    param_1 = 1;
  }
  while( true ) {
    iVar1 = heap_5_improved__60048774(param_1);
    if (iVar1 != 0) {
      return;
    }
    pcVar2 = (code *)thunk_FUN_600cc9c4();
    if (pcVar2 == (code *)0x0) break;
    (*pcVar2)();
  }
                    /* WARNING: Subroutine does not return */
  thunk_FUN_6010209a();
}


