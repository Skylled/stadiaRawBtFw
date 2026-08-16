// 600ab424  FUN_600ab424  size=304 bytes
// --- callers ---
//   600c6e94 FUN_600c6e94
//   600aac04 FUN_600aac04
// --- callees ---
//   600f4ed6 FUN_600f4ed6
//   600d9290 FUN_600d9290
//   600afd28 FUN_600afd28
//   600af3f4 FUN_600af3f4
//   600f6c4c FUN_600f6c4c
//   600f6668 FUN_600f6668
//   600af598 FUN_600af598
//   600afc84 FUN_600afc84
//   600afbd0 FUN_600afbd0
//   600adbfc FUN_600adbfc
//   6006ddd8 FUN_6006ddd8
//   600af240 FUN_600af240


undefined4 FUN_600ab424(undefined1 param_1,undefined2 param_2,char param_3)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar2 = FUN_600afd28(param_1);
  if (iVar2 == 0) {
    uVar4 = 10;
  }
  else {
    iVar2 = FUN_600af3f4(param_2);
    if (iVar2 == 0) {
      uVar4 = 10;
    }
    else {
      iVar3 = FUN_600afbd0(iVar2 + 8,iVar2 + 0x1c,*(undefined2 *)(iVar2 + 0x30));
      if (iVar3 == 10) {
        bVar1 = FUN_600afc84(iVar2);
        if (bVar1 == 10) {
          uVar4 = 0x80;
        }
        else {
          iVar3 = (uint)bVar1 * 0x28 + DAT_600ab554;
          *(undefined1 *)(iVar3 + 0xaa8) = param_1;
          if (((param_3 == '\x01') || (param_3 == '\x03')) && (*(short *)(iVar3 + 0xaa2) == 0x2800))
          {
            uVar4 = FUN_600f4ed6(*(undefined4 *)(iVar3 + 0xa84));
            uVar4 = FUN_600f6c4c(uVar4,*(undefined2 *)(iVar3 + 0xaa4),*(undefined2 *)(iVar3 + 0xaa6)
                                );
            *(undefined4 *)(iVar3 + 0xa9c) = uVar4;
          }
          FUN_600af598(bVar1,*(undefined2 *)(iVar3 + 0xaa4),*(undefined1 *)(iVar2 + 0x36));
          FUN_600f6668(DAT_600ab558,(bVar1 + 0xfb) * 0x10 + DAT_600ab554);
          iVar2 = FUN_600af240(iVar2 + 8,iVar2 + 0x1c,*(undefined2 *)(iVar2 + 0x30));
          if (iVar2 != 0) {
            FUN_600adbfc();
            uVar4 = FUN_600d9290(DAT_600ab55c,iVar2);
            FUN_6006ddd8(uVar4,DAT_600ab560,0x223);
          }
          uVar4 = 0;
        }
      }
      else {
        uVar4 = 0x8c;
      }
    }
  }
  return uVar4;
}


