// 600d1a62  FUN_600d1a62  size=58 bytes
// --- callers ---
//   600644dc usb_host_audio_topology__600644dc
// --- callees ---
//   600d18d2 FUN_600d18d2


char FUN_600d1a62(int param_1)

{
  int iVar1;
  char cVar2;
  undefined4 uStack_10;
  int local_c;
  
  if (param_1 != 0) {
    local_c = *(int *)(param_1 + 0x34);
    if (local_c == 0) {
      return '\x01';
    }
    cVar2 = '\0';
    uStack_10._0_2_ = (undefined2)param_1;
    uStack_10 = CONCAT22(*(undefined2 *)(param_1 + 0x38),(undefined2)uStack_10) & 0xffff00ff;
    do {
      cVar2 = cVar2 + '\x01';
      iVar1 = FUN_600d18d2(&local_c,(int)&uStack_10 + 2,(int)&uStack_10 + 1);
      if (iVar1 != 0) {
        return cVar2;
      }
    } while (cVar2 != '\n');
  }
  return '\0';
}


