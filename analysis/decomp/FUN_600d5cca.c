// 600d5cca  FUN_600d5cca  size=50 bytes
// --- callers ---
//   600641a8 usb_host_audio_topology__600641a8
// --- callees ---
//   600d5cc4 FUN_600d5cc4


uint FUN_600d5cca(undefined4 *param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  
  iVar2 = FUN_600d5cc4();
  if (iVar2 != 0) {
    pbVar4 = (byte *)*param_1;
    if (pbVar4[4] + 5 <= (uint)*pbVar4) {
      uVar3 = 0;
      pbVar5 = pbVar4 + 5;
      while ((int)uVar3 < (int)(uint)pbVar4[4]) {
        bVar1 = *pbVar5;
        uVar3 = uVar3 + 1;
        pbVar5 = pbVar5 + 1;
        if (param_2 == bVar1) {
          return uVar3 & 0xff;
        }
      }
    }
  }
  return 0xff;
}


