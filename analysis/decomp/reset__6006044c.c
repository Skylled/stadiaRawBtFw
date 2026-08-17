// 6006044c  reset__6006044c  size=126 bytes
// src: reset.cc
// --- callers ---
//   600604dc reset__600604dc
// --- callees ---
//   601016a2 FUN_601016a2
//   6005f164 FUN_6005f164
//   601016f0 FUN_601016f0
//   60060368 FUN_60060368
//   60101b76 FUN_60101b76
//   600d4772 FUN_600d4772
//   6005f18c FUN_6005f18c


/* src: reset.cc */

void reset__6006044c(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *local_a0;
  undefined4 local_9c;
  undefined4 uStack_98;
  undefined1 local_94;
  undefined1 local_93;
  undefined1 local_92 [134];
  
  if (param_2 == 1) {
    *(undefined4 *)(DAT_600604cc + 0x30) = 4;
  }
  else if (param_2 != 0) {
    if (param_2 != 2) {
      return;
    }
    goto LAB_60060468;
  }
  FUN_60060368();
LAB_60060468:
  uVar1 = DAT_600604d0;
  local_a0 = local_92;
  local_94 = 0;
  local_93 = 0;
  local_92[0] = 0;
  local_9c = 0x80;
  uStack_98 = 0;
  FUN_60101b76(&local_a0,DAT_600604d4);
  FUN_601016f0(0x14,uVar1,0x45,&local_a0);
  iVar2 = FUN_600d4772();
  if (iVar2 != 0) {
    FUN_6005f18c(0,1,0);
    FUN_601016a2(uVar1,0x49,DAT_600604d8);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  FUN_6005f164();
  FUN_601016a2(uVar1,0x4c,DAT_600604d8);
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


