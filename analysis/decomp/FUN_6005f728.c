// 6005f728  FUN_6005f728  size=386 bytes
// --- callers ---
//   60083e30 FUN_60083e30
// --- callees ---
//   6005e7b4 FUN_6005e7b4
//   600d46ce FUN_600d46ce
//   6005e7a4 FUN_6005e7a4
//   600d4d2e FUN_600d4d2e
//   60061bb0 FUN_60061bb0
//   600d469e FUN_600d469e
//   60100b0a FUN_60100b0a
//   6005e7e0 bug_report__6005e7e0
//   6005f664 FUN_6005f664


void FUN_6005f728(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int extraout_r3;
  int iVar4;
  uint uVar5;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  uVar3 = *(uint *)(DAT_6005f8ac + 0x28);
  local_14 = 0;
  local_10 = 0;
  uStack_c = 0;
  uVar5 = *(uint *)(DAT_6005f8ac + 4) & 0x1ff;
  iVar2 = param_1;
  iVar4 = DAT_6005f8ac;
  if (uVar5 != 3) goto LAB_6005f7b8;
  if ((int)(*(uint *)(DAT_6005f8ac + 0x2c) << 1) < 0) {
    uVar5 = 2;
  }
  else if ((*(uint *)(DAT_6005f8ac + 0x2c) & 2) == 0) {
    uVar5 = 1;
  }
  else {
    uVar5 = 3;
  }
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          FUN_6005f664(uVar5,param_1,&local_14,0,0);
          if (uVar5 != 2) {
            *DAT_6005f8b0 = (char)uVar5;
            puVar1 = DAT_6005f8b4;
            *DAT_6005f8b4 = local_14;
            puVar1[1] = local_10;
            puVar1[2] = uStack_c;
          }
          FUN_60061bb0(DAT_6005f8b8,uVar5,&local_14);
          FUN_6005e7a4();
          if ((uVar5 == 2) && (*DAT_6005f8b0 != '\0')) {
            FUN_600d46ce(*DAT_6005f8b0,DAT_6005f8b4);
          }
          FUN_600d469e();
          FUN_6005e7b4();
          bug_report__6005e7e0(uVar5,param_1);
          FUN_6005e7b4();
          iVar2 = FUN_600d4d2e();
          iVar4 = extraout_r3;
LAB_6005f7b8:
          if (uVar5 != 4) break;
          if ((int)(uVar3 << 0x18) < 0) {
            if ((int)(uVar3 << 0x1e) < 0) {
              if (*(uint *)(iVar4 + 0x34) < 0xff) {
                uVar5 = 9;
              }
              else {
                uVar5 = 5;
              }
            }
            if (((int)(uVar3 << 0x1e) < 0) &&
               (iVar2 = FUN_60100b0a(*(undefined4 *)(*DAT_6005f8bc + 0x30)), iVar2 != 0)) {
              uVar5 = 7;
            }
          }
          else {
            if ((int)(uVar3 << 0x1f) < 0) {
              if (*(uint *)(iVar2 + 0x58) < 0xff) {
                uVar5 = 8;
              }
              else {
                uVar5 = 6;
              }
            }
            if ((int)(uVar3 << 0x1b) < 0) {
              uVar5 = 10;
            }
            else if ((int)(uVar3 << 0x1c) < 0) {
              uVar5 = 0xb;
            }
            else if ((uVar3 & 0x20) != 0) {
              uVar5 = 0xc;
            }
          }
        }
        if (uVar5 == 5) break;
        if (uVar5 == 6) {
          if ((int)(uVar3 << 6) < 0) {
            uVar5 = 0x15;
          }
          else if ((int)(uVar3 << 7) < 0) {
            uVar5 = 0x16;
          }
          else if ((int)(uVar3 << 0xc) < 0) {
            uVar5 = 0x17;
          }
          else if ((int)(uVar3 << 0xd) < 0) {
            uVar5 = 0x18;
          }
          else if ((int)(uVar3 << 0xe) < 0) {
            uVar5 = 0x19;
          }
          else if ((uVar3 & 0x10000) == 0) {
            uVar5 = 0x14;
          }
          else {
            uVar5 = 0x1a;
          }
        }
        else {
          uVar5 = 1;
        }
      }
      if ((uVar3 & 0x8000) == 0) break;
      if ((uVar3 & 0x200) == 0) {
        uVar5 = 0x10;
      }
      else {
        uVar5 = 0xf;
      }
    }
    if ((int)(uVar3 << 0x15) < 0) {
      uVar5 = 0xe;
    }
    else if ((int)(uVar3 << 0x13) < 0) {
      uVar5 = 0x11;
    }
    else if ((int)(uVar3 << 0x14) < 0) {
      uVar5 = 0x12;
    }
    else if ((uVar3 & 0x2000) == 0) {
      uVar5 = 0xd;
    }
    else {
      uVar5 = 0x13;
    }
  } while( true );
}


