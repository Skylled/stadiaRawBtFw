// 6006573c  haptics__6006573c  size=204 bytes
// src: haptics.cc
// --- callers ---
//   600d6cf8 FUN_600d6cf8
// --- callees ---
//   600d4ada FUN_600d4ada
//   600d37b8 FUN_600d37b8
//   6013cf80 thunk_EXT_FUN_0000714c
//   6013d2a0 thunk_EXT_FUN_00007a2c
//   600cedd8 FUN_600cedd8
//   600656a0 haptics__600656a0
//   60051120 FUN_60051120
//   600601a4 FUN_600601a4
//   600655dc haptics__600655dc
//   60101b76 FUN_60101b76
//   60060284 FUN_60060284


/* src: haptics.cc */

uint haptics__6006573c(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  uint in_fpscr;
  float fVar6;
  undefined1 auStack_b4 [8];
  undefined1 auStack_ac [144];
  byte local_1c;
  
  if (param_2 == 0) {
    uVar2 = haptics__600656a0();
  }
  else {
    uVar5 = *(undefined4 *)(param_1 + 0x68);
    uVar3 = thunk_EXT_FUN_0000714c();
    iVar4 = thunk_EXT_FUN_00007a2c(uVar5,1,uVar3,0,10);
    if (iVar4 == 0) {
      FUN_60051120(auStack_b4,DAT_60065808,0x1d,4);
      FUN_60101b76(auStack_ac,DAT_6006580c);
      uVar2 = (uint)local_1c;
      FUN_600d37b8(auStack_b4);
    }
    else {
      fVar6 = (float)VectorSignedToFloat(param_2,(byte)(in_fpscr >> 0x16) & 3);
      uVar3 = haptics__600655dc((fVar6 * DAT_60065810) / DAT_60065814,param_1);
      iVar4 = *(int *)(param_1 + 4);
      if (((*(char *)(iVar4 + 10) != '\0') && (cVar1 = FUN_600601a4(iVar4), cVar1 != '\0')) ||
         ((*(char *)(iVar4 + 0x38) != '\0' && (cVar1 = FUN_60060284(uVar3,iVar4), cVar1 != '\0'))))
      {
        FUN_60051120(auStack_b4,DAT_60065808,0x20);
        FUN_60101b76(auStack_ac,DAT_60065818);
        FUN_600d37b8(auStack_b4);
      }
      FUN_600cedd8(*(undefined4 *)(*(int *)(param_1 + 8) + 0x20),
                   *(undefined4 *)(*(int *)(param_1 + 8) + 0x18),0);
      uVar2 = FUN_600d4ada(*(undefined4 *)(param_1 + 4));
    }
  }
  return uVar2;
}


