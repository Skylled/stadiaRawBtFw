// 600c1b74  FUN_600c1b74  size=138 bytes
// --- callers ---
//   600fabe0 FUN_600fabe0
//   600fabfa FUN_600fabfa
//   600fabc6 FUN_600fabc6
//   600fab3e FUN_600fab3e
//   600fac38 FUN_600fac38
//   600faac2 FUN_600faac2
//   600fab28 FUN_600fab28
//   600fac14 FUN_600fac14
//   600fabac FUN_600fabac
//   600fab92 FUN_600fab92
//   600fad26 FUN_600fad26
//   600fb8c4 FUN_600fb8c4
// --- callees ---
//   600c1a34 FUN_600c1a34
//   600c1b20 FUN_600c1b20
//   600aa340 FUN_600aa340
//   600aa3cc FUN_600aa3cc


char FUN_600c1b74(byte param_1,int param_2)

{
  int iVar1;
  undefined1 local_11;
  int local_10;
  char local_9;
  
  local_9 = '\0';
  local_11 = 0xf;
  if ((param_1 < 0x10) && (*(int *)(DAT_600c1c00 + (uint)param_1 * 4) != 0)) {
    local_10 = (**(code **)(DAT_600c1c00 + (uint)param_1 * 4))(param_1,param_2);
    if ((local_10 != 0) && (iVar1 = FUN_600c1b20(param_2 + 0x1d,local_10), iVar1 != 0)) {
      local_9 = '\x01';
      FUN_600aa3cc(param_2 + 4);
      FUN_600aa340(param_2 + 4,0x32,0x1e);
    }
  }
  if (local_9 == '\0') {
    FUN_600c1a34(param_2,0x17,&local_11);
  }
  return local_9;
}


