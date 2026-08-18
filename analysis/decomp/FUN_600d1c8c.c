// 600d1c8c  FUN_600d1c8c  size=154 bytes
// --- callers ---
//   6006318c usb_host_audio__6006318c
// --- callees ---
//   600d19ea FUN_600d19ea


uint FUN_600d1c8c(uint param_1,byte *param_2,uint param_3,uint param_4)

{
  bool bVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  byte *pbVar5;
  bool bVar6;
  undefined4 uStack_20;
  byte *local_1c;
  uint uStack_18;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0xc) == 0)) {
    uVar4 = 3;
  }
  else {
    uStack_20 = param_1;
    local_1c = param_2;
    uStack_18 = param_3;
    uVar4 = FUN_600d19ea(*(int *)(param_1 + 0xc),0,&local_1c,(int)&uStack_20 + 2);
    if (uVar4 == 0) {
      bVar6 = param_4 == 0xff;
      pbVar5 = local_1c + ((uStack_20 >> 0x10) - 4);
      bVar2 = false;
      bVar1 = false;
      for (; local_1c <= pbVar5; local_1c = local_1c + *local_1c) {
        if (local_1c[1] == 0x24) {
          bVar3 = local_1c[2];
          if (bVar3 == 2) {
            if ((byte *)(uint)local_1c[3] == param_2) {
              bVar1 = true;
              *(byte **)(param_1 + 0x44) = local_1c;
            }
          }
          else if (bVar3 == 3) {
            if (local_1c[3] == param_3) {
              *(byte **)(param_1 + 0x48) = local_1c;
              bVar2 = true;
            }
          }
          else if ((bVar3 == 6) && (local_1c[3] == param_4)) {
            *(byte **)(param_1 + 0x4c) = local_1c;
            bVar6 = true;
          }
        }
      }
      if ((bVar1) && (bVar2)) {
        bVar3 = bVar6 ^ 1;
      }
      else {
        bVar3 = 1;
      }
      uVar4 = (uint)bVar3;
    }
  }
  return uVar4;
}


