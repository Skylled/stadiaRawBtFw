// 600f5130  FUN_600f5130  size=446 bytes
// --- callers ---
//   600ae90c FUN_600ae90c
// --- callees ---
//   600f68f0 FUN_600f68f0
//   6013d3a0 thunk_EXT_FUN_0000b572
//   600ad4f4 FUN_600ad4f4
//   600f4f02 FUN_600f4f02


char FUN_600f5130(undefined4 param_1,int *param_2,undefined1 param_3,int param_4,ushort param_5,
                 ushort param_6,undefined4 param_7,undefined4 param_8,undefined4 param_9,
                 undefined4 param_10,undefined4 param_11,ushort *param_12,undefined1 param_13,
                 undefined1 param_14,undefined4 param_15,undefined2 *param_16)

{
  char cVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 local_24;
  undefined1 *local_20;
  ushort local_1a;
  undefined4 *local_18;
  char local_11;
  
  local_11 = '\n';
  local_1a = 0;
  local_20 = (undefined1 *)((uint)*(ushort *)(param_4 + 2) + param_4 + 0x15);
  if ((param_2 == (int *)0x0) || (*param_2 == 0)) {
    return '\n';
  }
  local_18 = (undefined4 *)*param_2;
  do {
    if (local_18 == (undefined4 *)0x0) {
      return local_11;
    }
    if (param_6 < *(ushort *)(local_18 + 3)) {
      return local_11;
    }
    if (*(char *)(local_18 + 2) == '\0') {
      local_34 = 2;
      local_30 = CONCAT22(local_30._2_2_,*(undefined2 *)((int)local_18 + 0xe));
    }
    else if (*(char *)(local_18 + 2) == '\x02') {
      local_34 = 4;
      local_30 = local_18[4];
    }
    else {
      local_34 = 0x10;
      thunk_EXT_FUN_0000b572(&local_30,(int)local_18 + 0xe,0x10);
    }
    if ((param_5 <= *(ushort *)(local_18 + 3)) &&
       (iVar2 = FUN_600f68f0(param_7,param_8,param_9,param_10,param_11,local_34,local_30,uStack_2c,
                             uStack_28,local_24), iVar2 != 0)) {
      if (*param_12 < 3) {
        return -0x80;
      }
      puVar3 = local_20 + 1;
      *local_20 = (char)*(undefined2 *)(local_18 + 3);
      local_20 = local_20 + 2;
      *puVar3 = (char)((ushort)*(undefined2 *)(local_18 + 3) >> 8);
      local_11 = FUN_600f4f02(local_18,0,&local_20,0,*param_12 - 2,&local_1a,param_13,param_14);
      if (local_11 == -0x78) {
        cVar1 = FUN_600ad4f4(param_1,param_3,*(undefined2 *)(local_18 + 3),0,param_15);
        return cVar1;
      }
      if (local_11 != '\0') {
        *param_16 = *(undefined2 *)(local_18 + 3);
        return local_11;
      }
      if (*(short *)(param_4 + 4) == 0) {
        *(ushort *)(param_4 + 4) = local_1a + 2;
      }
      if ((uint)*(ushort *)(param_4 + 4) != local_1a + 2) {
        return -0x80;
      }
      *(ushort *)(param_4 + 2) = local_1a + *(short *)(param_4 + 2) + 2;
      *param_12 = (*param_12 - local_1a) - 2;
      local_11 = '\0';
    }
    local_18 = (undefined4 *)*local_18;
  } while( true );
}


