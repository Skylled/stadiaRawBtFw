// 600fa8d6  FUN_600fa8d6  size=492 bytes
// --- callers ---
// --- callees ---
//   600c1a34 FUN_600c1a34
//   600a4060 FUN_600a4060


void FUN_600fa8d6(int *param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  undefined4 local_14;
  undefined1 local_10;
  undefined1 local_f;
  char local_9;
  
  if ((*param_1 != 0) && (*(char *)((int)param_1 + 0x2a) != '\0')) {
    cVar1 = *(char *)((int)param_1 + 0x2a);
    if (cVar1 == '\x06') {
      local_14 = *param_2;
    }
    else if (cVar1 == '\b') {
      if (*(char *)((int)param_1 + 0x196) == '\0') {
        return;
      }
      if (*(char *)((int)param_1 + 0x18d) != '\x02') {
        return;
      }
      if (*(char *)((int)param_1 + 0x18e) == '\x02') {
        return;
      }
      if (*(char *)((int)param_1 + 0x18e) == '\x03') {
        return;
      }
      local_14 = CONCAT31(local_14._1_3_,(char)param_1[0x66]);
    }
    else if (cVar1 == '\x01') {
      local_14._1_3_ = (uint3)*(byte *)((int)param_1 + 0x191) << 8;
      local_14 = CONCAT31(local_14._1_3_,4);
      local_14 = CONCAT13(0x10,(undefined3)local_14);
      local_10 = (undefined1)param_1[0x6d];
      local_f = *(undefined1 *)((int)param_1 + 0x1b5);
    }
    local_9 = (*(code *)*param_1)(*(undefined1 *)((int)param_1 + 0x2a),(int)param_1 + 0x1d,&local_14
                                 );
    if ((local_9 == '\0') && (*(char *)((int)param_1 + 0x2a) == '\x01')) {
      *(undefined1 *)((int)param_1 + 0x192) = local_14._2_1_;
      *(undefined1 *)((int)param_1 + 0x18e) = (undefined1)local_14;
      *(undefined1 *)(param_1 + 100) = local_14._1_1_;
      *(undefined1 *)((int)param_1 + 0x1b1) = local_14._3_1_;
      *(undefined1 *)(param_1 + 0x6d) = local_10;
      *(undefined1 *)((int)param_1 + 0x1b5) = local_f;
      if ((*(byte *)((int)param_1 + 0x192) & 1) == 0) {
        *(undefined1 *)(param_1 + 0x6d) = 0;
        *(undefined1 *)((int)param_1 + 0x1b5) = 0;
      }
      iVar2 = FUN_600a4060();
      *(bool *)((int)param_1 + 0x193) = iVar2 == 6;
      if (*(char *)((int)param_1 + 0x193) != '\0') {
        *(byte *)((int)param_1 + 0x192) = *(byte *)((int)param_1 + 0x192) | 8;
      }
      if ((*(byte *)((int)param_1 + 0x192) & 8) == 0) {
        *(byte *)((int)param_1 + 0x192) = *(byte *)((int)param_1 + 0x192) & 0xef;
        *(byte *)(param_1 + 0x6d) = *(byte *)(param_1 + 0x6d) & 0xf7;
        *(byte *)((int)param_1 + 0x1b5) = *(byte *)((int)param_1 + 0x1b5) & 0xf7;
      }
      *(byte *)(param_1 + 0x6d) = *(byte *)(param_1 + 0x6d) & 0xf7;
      *(byte *)((int)param_1 + 0x1b5) = *(byte *)((int)param_1 + 0x1b5) & 0xf7;
      FUN_600c1a34(param_1,0x14,0);
    }
  }
  if ((*(char *)((int)param_1 + 0x2a) == '\0') && (*(char *)((int)param_1 + 0x1fb) != '\0')) {
    *(undefined1 *)((int)param_1 + 0x1fb) = 0;
    FUN_600c1a34(param_1,0x1a,0);
  }
  return;
}


