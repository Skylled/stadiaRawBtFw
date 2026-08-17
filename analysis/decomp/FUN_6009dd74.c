// 6009dd74  FUN_6009dd74  size=180 bytes
// --- callers ---
//   600a1fc8 FUN_600a1fc8
// --- callees ---
//   6009f990 FUN_6009f990
//   600987dc FUN_600987dc
//   600aa340 FUN_600aa340
//   6009bfb0 FUN_6009bfb0
//   6009e6c0 FUN_6009e6c0


char FUN_6009dd74(byte param_1,char param_2,char param_3,undefined4 param_4)

{
  byte *pbVar1;
  int iVar2;
  char local_9;
  
  iVar2 = DAT_6009de2c;
  pbVar1 = DAT_6009de28;
  local_9 = '\x01';
  if (((*DAT_6009de28 & 0x30) == 0) && ((*DAT_6009de28 & 0x40) == 0)) {
    if ((*DAT_6009de28 & 0xf0) == 0) {
      FUN_6009bfb0(0);
      FUN_6009f990(2);
      if (param_3 == '\x02') {
        FUN_600987dc(param_4);
      }
      pbVar1[0xd] = 0;
      local_9 = FUN_6009e6c0();
    }
    if (local_9 == '\x01') {
      *(byte *)(iVar2 + 0x61e) = param_1 | *(byte *)(iVar2 + 0x61e);
      *pbVar1 = param_1 | *pbVar1;
      if (param_2 != '\0') {
        FUN_600aa340(iVar2 + 0x48,0x2f,param_2);
      }
    }
  }
  else {
    local_9 = '\x02';
  }
  return local_9;
}


