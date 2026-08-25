// 600f4f02  FUN_600f4f02  size=408 bytes
// --- callers ---
//   600f5130 FUN_600f5130
//   600f5478 FUN_600f5478
// --- callees ---
//   600f69f0 FUN_600f69f0
//   600ad130 FUN_600ad130


char FUN_600f4f02(int *param_1,undefined2 param_2,undefined4 *param_3,undefined1 param_4,
                 ushort param_5,ushort *param_6,undefined1 param_7,undefined1 param_8)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined1 *local_20;
  int *local_1c;
  char local_15;
  short local_14;
  ushort local_12;
  
  local_12 = 0;
  local_14 = 0;
  local_20 = (undefined1 *)*param_3;
  local_1c = param_1;
  local_15 = FUN_600ad130(param_1,param_2,param_4,param_7,param_8);
  if (local_15 == '\0') {
    if ((char)local_1c[2] == '\0') {
      local_14 = *(short *)((int)local_1c + 0xe);
    }
    local_15 = -0x80;
    if ((local_14 == 0x2800) || (local_14 == 0x2801)) {
      local_12 = *(ushort *)local_1c[1];
      if (*(ushort *)local_1c[1] <= param_5) {
        puVar3 = (undefined4 *)local_1c[1];
        FUN_600f69f0(&local_20,*puVar3,puVar3[1],puVar3[2],puVar3[3],puVar3[4]);
        local_15 = '\0';
      }
    }
    else if (local_14 == 0x2803) {
      if (*(char *)(*local_1c + 8) == '\0') {
        local_12 = 5;
      }
      else {
        local_12 = 0x13;
      }
      if (local_12 <= param_5) {
        *local_20 = *(undefined1 *)local_1c[1];
        local_20[1] = (char)*(undefined2 *)(local_1c[1] + 2);
        puVar1 = local_20 + 3;
        local_20[2] = (char)((ushort)*(undefined2 *)(local_1c[1] + 2) >> 8);
        if (*(char *)(*local_1c + 8) == '\0') {
          puVar2 = local_20 + 4;
          *puVar1 = (char)*(undefined2 *)(*local_1c + 0xe);
          local_20 = local_20 + 5;
          *puVar2 = (char)((ushort)*(undefined2 *)(*local_1c + 0xe) >> 8);
        }
        else {
          local_20 = puVar1;
          if (*(char *)(*local_1c + 8) == '\x02') {
            FUN_600af9a0(puVar1,*(undefined4 *)(*local_1c + 0x10));
            local_20 = local_20 + 0x10;
          }
          else {
            for (iVar4 = 0; iVar4 < 0x10; iVar4 = iVar4 + 1) {
              *local_20 = *(undefined1 *)(*local_1c + iVar4 + 0xe);
              local_20 = local_20 + 1;
            }
          }
        }
        local_15 = '\0';
      }
    }
    else if (local_14 == 0x2802) {
      if (*(short *)local_1c[1] == 2) {
        local_12 = 6;
      }
      else {
        local_12 = 4;
      }
      if (local_12 <= param_5) {
        *local_20 = (char)*(undefined2 *)(local_1c[1] + 0x16);
        local_20[1] = (char)((ushort)*(undefined2 *)(local_1c[1] + 0x16) >> 8);
        local_20[2] = (char)*(undefined2 *)(local_1c[1] + 0x18);
        local_20[3] = (char)((ushort)*(undefined2 *)(local_1c[1] + 0x18) >> 8);
        puVar1 = local_20 + 4;
        if (*(short *)local_1c[1] == 2) {
          local_20[4] = (char)*(undefined2 *)(local_1c[1] + 4);
          local_20[5] = (char)((ushort)*(undefined2 *)(local_1c[1] + 4) >> 8);
          puVar1 = local_20 + 6;
        }
        local_20 = puVar1;
        local_15 = '\0';
      }
    }
    else {
      local_15 = -0x78;
    }
    *param_6 = local_12;
    *param_3 = local_20;
  }
  return local_15;
}


