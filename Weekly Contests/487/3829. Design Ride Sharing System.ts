class RideSharingSystem {
  private riderQueue: number[];
  private driverQueue: number[];
  private activeRiders: Set<number>;
  constructor() {
    this.riderQueue = [];
    this.driverQueue = [];
    this.activeRiders = new Set();
  }

  addRider(riderId: number): void {
    this.riderQueue.push(riderId);
    this.activeRiders.add(riderId);
  }

  addDriver(driverId: number): void {
    this.driverQueue.push(driverId);
  }

  matchDriverWithRider(): number[] {
    while (
      this.riderQueue.length > 0 &&
      !this.activeRiders.has(this.riderQueue[0])
    ) {
      this.riderQueue.shift();
    }

    if (this.riderQueue.length == 0 || this.driverQueue.length == 0) {
      return [-1, -1];
    }

    const riderId = this.riderQueue.shift()!;
    const driverId = this.driverQueue.shift()!;

    this.activeRiders.delete(riderId);

    return [driverId, riderId];
  }

  cancelRider(riderId: number): void {
    this.activeRiders.delete(riderId);
  }
}

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * var obj = new RideSharingSystem()
 * obj.addRider(riderId)
 * obj.addDriver(driverId)
 * var param_3 = obj.matchDriverWithRider()
 * obj.cancelRider(riderId)
 */
