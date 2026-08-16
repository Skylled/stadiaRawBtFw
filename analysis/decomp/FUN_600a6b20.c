// 600a6b20  FUN_600a6b20  size=468 bytes
// --- callers ---
//   600f2262 FUN_600f2262
//   600f2f2a FUN_600f2f2a
//   600a96d8 FUN_600a96d8
// --- callees ---
//   600f0c84 FUN_600f0c84
//   600a830c FUN_600a830c
//   600bc7e8 FUN_600bc7e8
//   6009feb8 FUN_6009feb8
//   60098f34 FUN_60098f34
//   600a6720 FUN_600a6720
//   600a7b44 FUN_600a7b44
//   600f1f82 FUN_600f1f82


void FUN_600a6b20(short param_1,char param_2,char param_3)

{
  byte bVar1;
  char cVar2;
  int iVar3;
  undefined1 local_d;
  int local_c;
  
  iVar3 = FUN_6009feb8(param_1);
  local_c = 0;
  bVar1 = FUN_60098f34(param_1);
  local_d = 1;
  if ((param_2 == '#') || (param_2 == '*')) {
    FUN_600a6720(param_1);
  }
  else {
    *(undefined4 *)(DAT_600a6cf4 + 0x1168) = 0;
    if (iVar3 != 0) {
      if ((param_2 == '\0') && (param_3 != '\0')) {
        if (param_1 == *(short *)(iVar3 + 0xc)) {
          *(ushort *)(iVar3 + 0x2a) = *(ushort *)(iVar3 + 0x2a) | 6;
        }
        else {
          *(ushort *)(iVar3 + 0x2a) = *(ushort *)(iVar3 + 0x2a) | 0x400;
          if ((*(ushort *)(iVar3 + 0x2a) & 0x2000) != 0) {
            *(ushort *)(iVar3 + 0x2a) = *(ushort *)(iVar3 + 0x2a) | 0x200;
          }
        }
      }
      if ((param_2 == '\0') && (param_3 == '\0')) {
        if (param_1 == *(short *)(iVar3 + 0xc)) {
          *(ushort *)(iVar3 + 0x2a) = *(ushort *)(iVar3 + 0x2a) & 0xfffb;
        }
        else {
          *(ushort *)(iVar3 + 0x2a) = *(ushort *)(iVar3 + 0x2a) & 0xfbff;
        }
      }
      if (bVar1 != 4) {
        local_c = (uint)bVar1 * 0x14c + 0x110 + DAT_600a6cf4;
      }
      if (local_c != 0) {
        local_d = *(undefined1 *)(local_c + 0x12e);
      }
      FUN_600a830c(iVar3,local_d,param_3);
      if ((local_c == 0) || (*(char *)(local_c + 0x12e) != '\x02')) {
        *(undefined1 *)(iVar3 + 0x60) = 0x10;
        if (*(char *)(iVar3 + 0x50) == '\x02') {
          *(undefined1 *)(iVar3 + 0x50) = 0;
          if (param_2 == '\0') {
            cVar2 = FUN_600a7b44(iVar3);
            if (cVar2 != '\x01') {
              FUN_600f1f82(iVar3,cVar2,0);
            }
          }
          else {
            FUN_600f1f82(iVar3,10,0);
          }
        }
        else if (*(char *)(iVar3 + 0x50) == '\a') {
          *(undefined1 *)(iVar3 + 0x50) = 0;
          *(undefined4 *)(iVar3 + 0xf4) = 0;
          FUN_600bc7e8(iVar3 + 0x10);
        }
      }
      else {
        if (((param_2 == '\x06') || (param_2 == '\x05')) || (param_2 == '%')) {
          *(ushort *)(iVar3 + 0x2a) = *(ushort *)(iVar3 + 0x2a) & 0xefff;
          *(undefined1 *)(iVar3 + 0x7b) = 0;
        }
        FUN_600f0c84(iVar3 + 100,param_3);
      }
    }
  }
  return;
}


