// 600a3784  FUN_600a3784  size=380 bytes
// --- callers ---
//   600a3904 FUN_600a3904
// --- callees ---


ushort * FUN_600a3784(ushort *param_1,ushort *param_2,ushort *param_3)

{
  char cVar1;
  undefined4 uVar2;
  ushort uVar3;
  
  if (param_1 == (ushort *)0x0) {
    uVar2 = *(undefined4 *)(param_2 + 2);
    *(undefined4 *)param_3 = *(undefined4 *)param_2;
    *(undefined4 *)(param_3 + 2) = uVar2;
    param_3[4] = param_2[4];
    *(byte *)(param_3 + 4) = (byte)param_3[4] & 0xef;
    param_3 = param_2;
  }
  else if (((char)param_2[4] == '\0') || ((char)param_1[4] == '\0')) {
    param_3 = (ushort *)0x0;
  }
  else if ((param_1[4] & 0x10) == 0) {
    if ((param_2[4] & 0x10) == 0) {
      cVar1 = *(char *)(DAT_600a3900 +
                       (uint)(byte)(((char)param_2[4] + (char)param_1[4] * '\x03') - 4));
      if (cVar1 == '\x02') {
        uVar2 = *(undefined4 *)(param_2 + 2);
        *(undefined4 *)param_3 = *(undefined4 *)param_2;
        *(undefined4 *)(param_3 + 2) = uVar2;
        param_3[4] = param_2[4];
        param_3 = param_2;
      }
      else if (cVar1 == '\x03') {
        *(char *)(param_3 + 4) = (char)param_1[4];
        uVar3 = *param_1;
        if (*param_2 <= *param_1) {
          uVar3 = *param_2;
        }
        *param_3 = uVar3;
        uVar3 = param_1[1];
        if (param_1[1] < param_2[1]) {
          uVar3 = param_2[1];
        }
        param_3[1] = uVar3;
        if (*param_3 < param_3[1]) {
          param_3 = (ushort *)0x0;
        }
        else if ((char)param_3[4] == '\x02') {
          uVar3 = param_1[2];
          if (param_1[2] < param_2[2]) {
            uVar3 = param_2[2];
          }
          param_3[2] = uVar3;
          uVar3 = param_1[3];
          if (param_1[3] < param_2[3]) {
            uVar3 = param_2[3];
          }
          param_3[3] = uVar3;
        }
      }
      else if (cVar1 == '\x01') {
        uVar2 = *(undefined4 *)(param_1 + 2);
        *(undefined4 *)param_3 = *(undefined4 *)param_1;
        *(undefined4 *)(param_3 + 2) = uVar2;
        param_3[4] = param_1[4];
        param_3 = param_1;
      }
      else {
        param_3 = (ushort *)0x0;
      }
    }
    else {
      uVar2 = *(undefined4 *)(param_2 + 2);
      *(undefined4 *)param_3 = *(undefined4 *)param_2;
      *(undefined4 *)(param_3 + 2) = uVar2;
      param_3[4] = param_2[4];
      *(byte *)(param_3 + 4) = (byte)param_3[4] & 0xef;
    }
  }
  else {
    uVar2 = *(undefined4 *)(param_1 + 2);
    *(undefined4 *)param_3 = *(undefined4 *)param_1;
    *(undefined4 *)(param_3 + 2) = uVar2;
    param_3[4] = param_1[4];
    *(byte *)(param_3 + 4) = (byte)param_3[4] & 0xef;
  }
  return param_3;
}


